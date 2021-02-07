#include "open_window.h"

#include <fstream>

#include "QHBoxLayout"
#include "map_save.h"
#include <fstream>
#include "QScrollArea"
#include "QMessageBox"
#include "editor.h"
#include "ui_editor.h"
#include "map_actions.h"
#include "tile_item.h"
#include "ui_open_window.h"
#include "map_canvas.h"

#define MAP_NAME_PATH "./maps/maps_names.txt"

open_window::open_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::open_window)
{
    ui->setupUi(this);
    QVBoxLayout* ly = new QVBoxLayout();
    ly->setSpacing(10);
    std::ifstream reader;
    std::string line;
    reader.open(MAP_NAME_PATH, std::ifstream::in);
    while (reader.good()) {
        std::getline(reader, line, '\n');
        if(line.empty()){
            continue;
        }
        map_save* ms = new map_save(this, line);
        ly->addWidget(ms,0,Qt::AlignTop);
     }
    reader.close();
    ui->map_saved_container->setLayout(ly);
    this->map_selected = NULL;
    this->editor = (Editor*) parent;
}

open_window::~open_window()
{
    delete ui;
}

void open_window::on_open_boton_clicked()
{
    if(this->map_selected == NULL){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No has seleccionado un mapa!!");
        messageBox.setFixedSize(500,200);
        messageBox.exec();
    }else{
        map_canvas* new_mc = new map_canvas(this->map_selected);
        if(this->editor->my_map_scene == NULL){
            int cant_rows = new_mc->grilla.size();
            int cant_col = new_mc->grilla.at(0).size();
            editor->my_map_scene = new class map_scene(this->editor);
            editor->ui->graphics_map_container->setScene(editor->my_map_scene);
            map_actions* ma = new map_actions(editor, editor->my_map_scene);
            editor->ui->graphics_map_container->installEventFilter(ma);
            editor->ui->actionsafe->setEnabled(true);

        }else{
           this->editor->my_map_scene->clear();
        }
        this->editor->mc = new_mc;
        editor->actual_map_name = this->map_name;
        this->close();
    }
}
