//
// Created by rodri on 24/10/23.
//
#include <iostream>
#include "Student.cpp"
#include "Class.cpp"
#include <string>

using namespace std;


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



int command() {
    int choice;
    string estudante,turma,uc;
    do {
        cout << "\n 0. Ver horario de estudante \n 1. Ver horario de Turma \n 2. Alterar Turma de estudante(nao implementado)\n 3. Creditos\n 4. Exit\n\n";
        cin >> choice;
        switch (choice) {
            case 0:
            {
                /*
                cout << "Insira o numero de estudante \n";
                cin>>estudante;
                Gestor gestor;
                set<EstudanteTurma> horarioestudante =gestor.HorarioEstudante(estudante);
                printhorarioestudante(horarioestudante,estudante);
                break;
                 */
            }
            case 1:
            {
                /*
                string turma;
                Gestor gestor;
                cout<<"Insira a turma de que quer ver horario \n";
                cin>>turma;
                printhorarioturma(gestor.HorarioTurma(),turma);
                break;
                */
            }
            case 2:
            {
                /*
                cout << "Insira o numero de estudante\n";
                cin >> estudante;
                cout << "Insira a UC de que pretende alterar a turma\n";
                cin >> uc;
                cout << "Insira a turma para a qual quer mudar \n";
                cin >> turma;
                */
                break;
            }
            case 3:
                cout << "Done by André de Sousa, Rodrigo de Sousa and Álvaro Pacheco\n";
                cout << "Group 1305\n";
                break;
            case 4:
                return 0;
            default:
                return 0;
        }
    } while (choice);
}

int main() {
    command();
}
