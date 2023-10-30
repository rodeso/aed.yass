//
// Created by rodri on 24/10/23.
//
#include <iostream>
#include "Student.cpp"
#include "Class.cpp"

namespace uni {
    void Controller::parseDataStudent(const std::string& file) {
        std::ifstream fileStream(file); //load do ficheiro

        if (!fileStream.is_open()) { //verifica se foi possivel abrir o ficheiro
            throw std::runtime_error("Failed to open file");
            return nullptr;
        }

        std::string line;
        getline(fileStream, line);
        if (line != "StudentCode,StudentName,UcCode,ClassCode") { //primeira linha
            throw std::runtime_error("Invalid file format");
            return nullptr;
        }

        getline(fileStream, line);
        std::istringstream iss(line);
        int width, height, num_colors, chars_per_pixel;
        if (!(iss >> width >> height >> num_colors >> chars_per_pixel)) { //segunda linha
        throw std::runtime_error("Invalid XPM header format");
        return nullptr;
    }

    std::unordered_map<char, Color> colorMap;
    //percorre as linhas codificadas para adiquirir as cores em função dos simbolos/chaves
    for (int i = 0; i < num_colors; i++) {
    getline(fileStream, line);
    std::istringstream colorIss(line);
    char symbol; //chave para o map e cores no XMP
    char letter; //neste caso apenas c
    std::string hex; //hex que será convertido para rgb
    if (!(colorIss >> symbol >> letter >> hex)) {
    throw std::runtime_error("Invalid color definition in XPM file");
    return nullptr;
    }
    Color color = getColor(hex); //converte hex para rgb
    colorMap[symbol] = color; //adiciona a chave e cores no map
    }
    }
    int main() {

    }
}