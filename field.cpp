#ifndef field_h
#define field_h
#include "field.h"
#define ERROR_VALUE throw std::out_of_range("Недопустимое значение переменной!")




Field::Field(int height, int width) : width(width), height(height), start_position({0,0}), end_position({0,0}){
    if (height <= 0 || height > 100 || width <= 0 || width > 100)
        ERROR_VALUE;
    init_field(this->width, this->height);
}

Field::Field(const Field& other):width(other.width), height(other.height){
    init_field(width, height);
    start_position = other.start_position;
    end_position = other.end_position;
    for (int i = 0; i < other.width; ++i){
        for (int j = 0; j < other.height; ++j){
            array_cells[i][j] = other.array_cells[i][j];
            array_cells[i][j].set_event(other.array_cells[i][j].get_event());
        }
    }
           // std::copy(array_cells[i], array_cells[i] + height, other.array_cells[i]);
}

Field& Field::operator = (const Field& other){
    if (this != &other){
        start_position = other.start_position;
        end_position = other.end_position;
        del_field(this->width);
        init_field(other.width, other.height);
        for (int i = 0; i < other.width; ++i){
            for (int j = 0; j < other.height; ++j){
                array_cells[i][j] = other.array_cells[i][j];
                array_cells[i][j].set_event(other.array_cells[i][j].get_event());
            }
    }
        width = other.width;
        height = other.height;
    }
    return *this;
  }

Field::Field(Field&& other) : width(0), height(0){
    std::swap(start_position, other.start_position);
    std::swap(end_position, other.end_position);
    other.start_position = {0, 0};
    other.end_position = {0, 0};
    array_cells = other.array_cells;
    other.array_cells = nullptr;
    std::swap(width, other.width);
    std::swap(height, other.height);
}

Field& Field::operator = (Field&& other){
    if (this != &other){
        std::swap(start_position, other.start_position);
        std::swap(end_position, other.end_position);
        other.start_position = {0, 0};
        other.end_position = {0, 0};
        del_field(width);
        width = 0;
        height = 0;
        std::swap(width, other.width);
        std::swap(height, other.height);
        array_cells = other.array_cells;
        other.array_cells = nullptr;  
    }
    return *this;
  }



Field::~Field(){
    del_field(this->width);
}

void Field::print_field(){
    std::cout << "Вход - X: " << start_position.x << " Y: " << start_position.y << '\n';
    std::cout << "Выход - X: " << end_position.x << " Y: " << end_position.y << '\n';
    for (int i = 0; i < this->width; ++i) {
            for (int j = 0; j < this->height; ++j) {
                std::cout << array_cells[i][j].getPassability() << ' ';
            }
            std::cout << '\n';
        }
}

bool Field::set_coords_end(Point end){
    if (end.x >= 0 && end.y >= 0 && end.x < width && end.y < height){
        this->end_position = end;
        return true;    
    }else{
        return false;
    }
}
bool Field::set_coords_start(Point start){
    if (start.x >= 0 && start.y >= 0 && start.x < width && start.y < height){
        this->start_position = start;
        return true;
    }else{
        return false;
    }
}
Point Field::get_coords_start(){
    return start_position;
}
Point Field::get_coords_end(){
    return end_position;
}

int Field::get_height(){
    return height;
}
int Field::get_width(){
    return width;
}


void Field::init_field(int width, int height){
    array_cells = new Cell*[width];
    for(int i = 0; i < this->width; ++i){
        array_cells[i] = new Cell[height];
    }
}

void Field::del_field(int width){
    for (int i = 0; i < width; ++i) {
        delete[] array_cells[i];
    }
    delete[] array_cells;
}

#endif