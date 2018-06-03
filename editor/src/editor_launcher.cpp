#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QFileInfo>
#include <sstream>
#include <QLineEdit>
#include "editor_launcher.h"
#include "types.h"
#include "ui_editor_launcher.h"
#include "yaml.h"
#include "editor.h"

#define SAVED_MAPS_PATH "../maps/"
#define MAPS_EXT ".yml"

EditorLauncher::EditorLauncher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorLauncher)
{
    ui->setupUi(this);
    this->background_choosed = false;
    connectEvents();
}

EditorLauncher::~EditorLauncher()
{
    delete ui;
}

void EditorLauncher::connectEvents(void) {
    // Conecto el evento del boton exit

    QPushButton* choose_background = findChild<QPushButton*>("background_path");
    QObject::connect(choose_background, &QPushButton::clicked,
                     this, &EditorLauncher::chooseBackground);

    QPushButton* go_create = findChild<QPushButton*>("go_create");
    QObject::connect(go_create, &QPushButton::clicked,
                     this, &EditorLauncher::goCreate);
}

void EditorLauncher::chooseBackground(void) {
    QString bg_path;
    bg_path = QFileDialog::getOpenFileName(this, tr("Choose Background"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
    this->background_path = bg_path.toUtf8().constData();
    QLabel* label_background_path = findChild<QLabel*>("label_background_path");
    label_background_path->setText(bg_path);
    if (bg_path.length() > 0) {
        this->background_choosed = true;
        QFileInfo bg_info(bg_path);
        this->background_name = bg_info.fileName().toUtf8().constData();
    }
}

void EditorLauncher::goCreate(void) {

    QString error_msg;
    bool error = false;
    std::string map_name;
    YAML::Node mapNode;

    if (!this->background_choosed) {
        error_msg += "Choose a background! \n";
        error = true;
    }

    if (findChild<QComboBox*>("background_options")->currentText() == "Background Options") {
        error_msg += "Background option is missing.\n";
        error = true;
    }

    if (findChild<QLineEdit*>("map_name")->text().length() == 0) {
        error_msg += "Write a map name!.\n";
    }

    if (error == true) {
        findChild<QLabel*>("label_errors")->setText(error_msg);
        return;
    }

    map_name = findChild<QLineEdit*>("map_name")->text().toUtf8().constData();
    mapNode["static"]["background"]["file"] = this->background_path;
    mapNode["static"]["background"]["display"] = findChild<QComboBox*>("background_options")->currentText().toUtf8().constData();
    mapNode["static"]["water_level"] = findChild<QSpinBox*>("water_level")->value();
    mapNode["static"]["teams_amount"] = findChild<QSpinBox*>("teams_amount")->value();
    mapNode["static"]["worms_health"] = findChild<QSpinBox*>("worms_health")->value();

    YAML::Node mortar;
    mortar["item_name"] = "Mortar";
    mortar["supplies"] = findChild<QSpinBox*>("mortar_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(mortar);

    YAML::Node cluster;
    cluster["item_name"] = "Cluster";
    cluster["supplies"] = findChild<QSpinBox*>("red_bomb_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(cluster);

    YAML::Node banana;
    banana["item_name"] = "Banana";
    banana["supplies"] = findChild<QSpinBox*>("banana_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(banana);

    YAML::Node grenade;
    grenade["item_name"] = "Grenade";
    grenade["supplies"] = findChild<QSpinBox*>("green_bomb_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(grenade);

    YAML::Node holy_bomb;
    holy_bomb["item_name"] = "Holy bomb";
    holy_bomb["supplies"] = findChild<QSpinBox*>("holy_bomb_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(holy_bomb);

    YAML::Node dynamite;
    dynamite["item_name"] = "Dynamite";
    dynamite["supplies"] = findChild<QSpinBox*>("dynamite_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(dynamite);

    YAML::Node fly_bombs;
    fly_bombs["item_name"] = "Fly bombs";
    fly_bombs["supplies"] = findChild<QSpinBox*>("fly_bombs_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(fly_bombs);

    YAML::Node teleport;
    teleport["item_name"] = "Teleport";
    teleport["supplies"] = findChild<QSpinBox*>("teleport_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(teleport);

    YAML::Node bat;
    bat["item_name"] = "Bat";
    bat["supplies"] = findChild<QSpinBox*>("bat_ammo")->value();
    mapNode["static"]["init_inventory"].push_back(bat);

/*     std::string map_path = SAVED_MAPS_PATH + map_name + MAPS_EXT; */

/*     std::ofstream map_file(map_path, std::ofstream::out | std::ofstream::trunc);
    map_file << mapNode;
    map_file.close(); */

    launchEditor(mapNode, map_name);
}

void EditorLauncher::launchEditor(YAML::Node mapNode, std::string & map_name) {
    Editor the_editor(mapNode, map_name);
    this->hide();
    int err_code;
    err_code = the_editor.start();
    if (err_code == 0) {
        std::string cmd_create_folder_map = "mkdir ../maps/" + map_name;
        std::system(cmd_create_folder_map.c_str());
        std::string cmd_cp_background = "cp " + this->background_path + " ../maps/" + map_name;
        std::system(cmd_cp_background.c_str());
        std::string cmd_mv_yaml = "mv ../maps/" + map_name + ".yml" + " ../maps/" + map_name + "/";
        std::system(cmd_mv_yaml.c_str());
    }
    this->close();
}