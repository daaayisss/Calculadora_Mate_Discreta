#include <iostream>
#include <vector>

using namespace std;

// =================== Orden de ejecucion ===================
void MenuPrincipal();
void MenuPermutaciones();
void MenuCombinaciones();
void PermutacionesSinRepeticion();
void PermutacionesConRepeticion();
void PermutacionesDePalabra();
void CombinacionesSinRepeticion();
void CombinacionesConRepeticion();
void Salida();

// =================== Factorial ===================
unsigned long long factorial(int n) {
    unsigned long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

// =================== potencia entera (para "con repetición") ===================
unsigned long long potencia(unsigned long long base, int exp) {
    unsigned long long r = 1;
    for (int i = 0; i < exp; i++) r *= base;
    return r;
}

// =================== contar letras distintas en un vector<char> sin map ===================
int contarDistintas(const vector<char>& a) {
    int n = (int)a.size();
    vector<bool> visto(n, false);
    int distintas = 0;
    for (int i = 0; i < n; i++) {
        if (visto[i]) continue;
        distintas++;
        for (int j = i; j < n; j++)
            if (a[j] == a[i]) visto[j] = true;
    }
    return distintas;
}

// =================== permutaciones de palabra SIN repetición (multinomial) ===================
unsigned long long permPalabraSinRep(const vector<char>& a) {
    int n = (int)a.size();
    unsigned long long res = factorial(n);
    vector<bool> usado(n, false);

    for (int i = 0; i < n; i++) {
        if (usado[i]) continue;
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (a[j] == a[i]) { cnt++; usado[j] = true; }
        }
        if (cnt > 1) res /= factorial(cnt);
    }
    return res;
}

// =================== permutaciones de palabra CON repetición (#distintas)^n ===================
unsigned long long permPalabraConRep(const vector<char>& a) {
    int n = (int)a.size();
    int d = contarDistintas(a);
    return potencia(d, n);
}

// =================== Permutaciones sin repetición ===================
void PermutacionesSinRepeticion() {
    system("cls");
    int n, r;
    cout << "\n\tPERMUTACIONES SIN REPETICION\n";
    cout << "\tFormula: P(n,r) = n! / (n - r)!\n\n";

    cout << "\tIngrese n: "; cin >> n; // 5
    cout << "\tIngrese r: "; cin >> r; // 3

    if (r > n || n < 0 || r < 0) {
        cout << "\n\tError: r no puede ser mayor que n y ambos deben ser positivos.\n\n";
    }
    else {
        unsigned long long resultado = factorial(n) / factorial(n - r);
        cout << "\n\tResultado: P(" << n << "," << r << ") = " << resultado << "\n\n"; // Resultado: P(5,3) = 60
    }
    system("pause");
    system("cls");
}

// =================== Permutaciones con repetición ===================
void PermutacionesConRepeticion() {
    system("cls");
    int n, r;
    cout << "\n\tPERMUTACIONES CON REPETICION\n";
    cout << "\tFormula: P = n^r\n\n";

    cout << "\tIngrese n: "; cin >> n; // 10
    cout << "\tIngrese r: "; cin >> r; // 3

    if (n < 0 || r < 0) {
        cout << "\n\tError: n y r deben ser positivos.\n\n";
    }
    else {
        unsigned long long resultado = 1;
        for (int i = 0; i < r; i++) resultado *= n;
        cout << "\n\tResultado: " << n << "^" << r << " = " << resultado << "\n\n"; // Resultado: 10^3 = 1000
    }
    system("pause");
    system("cls");
}

// =================== Combinaciones sin repetición ===================
void CombinacionesSinRepeticion() {
    system("cls");
    int n, r;
    cout << "\n\tCOMBINACIONES SIN REPETICION\n";
    cout << "\tFormula: C(n,r) = n! / (r! * (n - r)!)\n\n";

    cout << "\tIngrese n: "; cin >> n; // 10
    cout << "\tIngrese r: "; cin >> r; // 4

    if (r > n || n < 0 || r < 0) {
        cout << "\n\tError: r no puede ser mayor que n y ambos deben ser positivos.\n\n";
    }
    else {
        unsigned long long resultado = factorial(n) / (factorial(r) * factorial(n - r));
        cout << "\n\tResultado: C(" << n << "," << r << ") = " << resultado << "\n\n"; // Resultado: C(10,4) = 210
    }
    system("pause");
    system("cls");
}

// =================== Combinaciones con repetición ===================
void CombinacionesConRepeticion() {
    system("cls");
    int n, r;
    cout << "\n\tCOMBINACIONES CON REPETICION\n";
    cout << "\tFormula: C(n+r-1, r) = (n+r-1)! / (r! * (n-1)!)\n\n";

    cout << "\tIngrese n: "; cin >> n; // 5
    cout << "\tIngrese r: "; cin >> r; // 3

    if (n < 0 || r < 0) {
        cout << "\n\tError: n y r deben ser positivos.\n\n";
    }
    else if (n == 0 && r > 0) {
        cout << "\n\tNo existen combinaciones si n=0 y r>0.\n\n";
    }
    else {
        unsigned long long resultado = factorial(n + r - 1) / (factorial(r) * factorial(n - 1));
        cout << "\n\tResultado: C(" << n << "," << r << ") = " << resultado << "\n\n"; // Resultado: C(5,3) = 35
    }
    system("pause");
    system("cls");
}

// =================== Menú Permutaciones ===================
void MenuPermutaciones() {
    system("cls");
    int opc = 0;
    do {
        cout << "\t============================================================\n";
        cout << "\t|1) Permutaciones SIN repeticion                           |\n";
        cout << "\t|2) Permutaciones CON repeticion                           |\n";
        cout << "\t|3) Problema con PALABRA (Permutaciones)                   |\n";
        cout << "\t|4) Menu Principal                                         |\n";
        cout << "\t============================================================\n";
        cout << "\tIngrese la opcion que desee utilizar: ";
        cin >> opc;
        system("cls");

        switch (opc) {
        case 1: PermutacionesSinRepeticion(); break;
        case 2: PermutacionesConRepeticion(); break;
        case 3: PermutacionesDePalabra(); break;
        case 4: MenuPrincipal(); break;
        default: cout << "\n\tOpcion invalida!\n\n"; system("pause"); break;
        }
    } while (opc != 4);
}

// =================== Menú Combinaciones ===================
void MenuCombinaciones() {
    system("cls");
    int opc = 0;
    do {
        cout << "\t============================================================\n";
        cout << "\t|1) Combinaciones SIN repeticion                           |\n";
        cout << "\t|2) Combinaciones CON repeticion                           |\n";
        cout << "\t|3) Menu Principal                                         |\n";
        cout << "\t============================================================\n";
        cout << "\tIngrese la opcion que desee utilizar: ";
        cin >> opc;
        system("cls");

        switch (opc) {
        case 1: CombinacionesSinRepeticion(); break;
        case 2: CombinacionesConRepeticion(); break;
        case 3: MenuPrincipal(); break;
        default: cout << "\n\tOpcion invalida!\n\n"; system("pause"); break;
        }
    } while (opc != 3);
}

// =================== resolver problema con palabra (array de letras) ===================
void PermutacionesDePalabra() {
    system("cls");
    cout << "\n\tPROBLEMA CON PALABRA (Permutaciones)\n";
    cout << "\t- Ingresa la palabra como lista de letras.\n\n"; 

    int n;
    cout << "\tCuantas letras tiene la palabra? ";// 8 letras computer
    cin >> n;

    if (n <= 0) {
        cout << "\n\tError: n debe ser positivo.\n\n";
        system("pause");
        return;
    }

    vector<char> letras(n);
    cout << "\n\tIngresa las " << n << " letras (una por una):\n";
    for (int i = 0; i < n; i++) {
        cout << "\tLetra " << (i + 1) << ": ";
        cin >> letras[i];
    }

    cout << "\n\tPalabra: ";
    for (char c : letras) cout << c;
    cout << "\n";

    unsigned long long sinRep = permPalabraSinRep(letras);
    unsigned long long conRep = permPalabraConRep(letras);

    cout << "\n\tFormas SIN repeticion: " << sinRep;
    cout << "\n\tFormas CON repeticion: " << conRep << "\n\n";

    system("pause");
    system("cls");
}

// =================== Menú Principal ===================
void MenuPrincipal() {
    system("cls");
    int opc = 0;
    do {
        cout << "\t==================================================\n";
        cout << "\t|1) Permutaciones                                |\n";
        cout << "\t|2) Combinaciones                                |\n";
        cout << "\t|3) Cerrar Programa                              |\n";
        cout << "\t==================================================\n";
        cout << "\tIngrese la opcion que desee utilizar: ";
        cin >> opc;
        system("cls");

        switch (opc) {
        case 1: MenuPermutaciones(); break;
        case 2: MenuCombinaciones(); break;
        case 3: Salida(); break;
        default: cout << "\n\tOpcion invalida!\n\n"; system("pause"); break;
        }
    } while (opc != 3);
}

// =================== Salida ===================
void Salida() {
    system("color 02");
    cout << "\n\tGracias por usar este programa ;)\n\n";
    exit(0);
}

// =================== main ===================
int main() {
    MenuPrincipal();
}
