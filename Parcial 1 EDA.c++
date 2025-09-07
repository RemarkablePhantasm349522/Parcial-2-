#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 
using namespace std;

int main() {
    int numDias;
    cout << "Cuantos dias se registraran? ";
    cin >> numDias;

    vector<float> temperaturas(numDias);
    for (int i = 0; i < numDias; ++i) {
        cout << "Temperatura del dia " << i + 1 << ": ";
        cin >> temperaturas[i];
    }

    float* ptr = temperaturas.data(); 
    float suma = 0.0;
    cout << "\nTemperaturas registradas:\n";
    for (int i = 0; i < numDias; ++i) {
        cout << "Dia " << i + 1 << ": " << *(ptr + i) << " grados\n";
        suma += *(ptr + i);
    }
    float promedio = suma / numDias;
    cout << "Temperatura promedio: " << promedio << " grados\n";

    float buscada;
    cout << "\nIngrese una temperatura a buscar: ";
    cin >> buscada;
    bool encontrada = false;
    for (int i = 0; i < numDias; ++i) {
        if (temperaturas[i] == buscada) {
            cout << "Temperatura encontrada en la posicion " << i << " (Dia " << i + 1 << ")\n";
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "La temperatura no existe en el registro.\n";
    }


    sort(temperaturas.begin(), temperaturas.end());
    cout << "\nTemperaturas ordenadas de menor a mayor:\n";
    for (float temp : temperaturas) {
        cout << temp << " grados ";
    }
    cout << "\n";


    list<string> equipos;
    int numEquipos;
    cout << "\nCuantos equipos se usaron para medir temperaturas? ";
    cin >> numEquipos;
    cin.ignore(); 

    for (int i = 0; i < numEquipos; ++i) {
        string nombre;
        cout << "Nombre del equipo " << i + 1 << ": ";
        getline(cin, nombre);
        equipos.push_back(nombre);
    }

    cout << "\nLista de equipos:\n";
    for (list<string>::iterator it = equipos.begin(); it != equipos.end(); ++it) {
        cout << "- " << *it << "\n";
    }

    string equipoBuscado;
    cout << "\nIngrese el nombre de un equipo a buscar: ";
    getline(cin, equipoBuscado);
    auto encontrado = find(equipos.begin(), equipos.end(), equipoBuscado);
    if (encontrado != equipos.end()) {
        cout << "Equipo encontrado: " << *encontrado << "\n";
    } else {
        cout << "Equipo no encontrado.\n";
    }

    equipos.sort();
    cout << "\nEquipos ordenados alfabeticamente:\n";
    for (const string& eq : equipos) {
        cout << "- " << eq << "\n";
    }

    string equipoEliminar;
    cout << "\nIngrese el nombre de un equipo a eliminar: ";
    getline(cin, equipoEliminar);
    equipos.remove(equipoEliminar);
    cout << "Lista actualizada de equipos:\n";
    for (const string& eq : equipos) {
        cout << "- " << eq << "\n";
    }

    return 0;
}
