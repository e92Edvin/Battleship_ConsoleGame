// Github - e92Edvin
// LinkedIn - https://www.linkedin.com/in/edvin-rusecki-848a3215b/

#include <bits/stdc++.h>
#include <conio.h>
#include <chrono>
#include <thread>
#include <windows.h>

#define Red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
#define Green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
#define Blue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);

using namespace std;

string num, let;
int arr[11][11] = {0};
int PC_arr[11][11] = {0};
int userSum, pcSum, out;
const int x = 96;
const int y = 10;
const int lost = 20;
const int a[11] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
bool chv = false, chw, chr, turn = true;
char PC_drown[11][11];

void Setup()
{
    for(int i=1; i<=y; i++)
        for(int j=1; j<=y; j++)
            PC_drown[i][j] = '*';
}

int Converter(string s)
{
    stringstream rev(s);
    int x;
    rev >> x;
    return x;
}

bool Check(string a, string b)
{
    bool str_a = false;
    bool str_b = false;
    for(char h = 'a'; h <= 'j'; h++)
        if(h == b[0] && b.size() == 1)
            str_b = true;

    int x = Converter(a);
    for(int i=1; i<=y; i++)
        if(x == i)
            str_a = true;

    if(str_a && str_b)
        return true;
    else
        return false;
}

void Show()
{
    Red;
    system("cls");
    cout << "   ";
    for(char h = 'a'; h <= 'j'; h++) cout << (char)toupper(h) << " ";
    cout << endl;

    for(int i=1; i<=y; i++){
            bool cvx = true;
            for(int j=1; j<=y; j++){
                if(i < y && cvx){
                    Red;
                    cout << " " << i << " ";
                    cvx = false;
                }
                else if(i == y && cvx){
                    Red;
                    cout << i << " ";
                    cvx = false;
                }
                if(arr[i][j] == 9) {Red;}
                else if (arr[i][j] == 0) {Blue;}
                else {Green;}
                cout << arr[i][j] << " ";
            }
        cout << endl;
    }
    Blue;
}

bool CheckDistance(int x, int y, int z)
{
    if(z > 1){
        if(x == 1 && arr[x+1][y] != 0 && arr[x][y+1] != 0 && arr[x][y-1] != 0) return false;
        if(x == 10 && arr[x-1][y] != 0 && arr[x][y+1] != 0 && arr[x][y-1] != 0) return false;
        if(y == 1 && arr[x+1][y] != 0 && arr[x-1][y] != 0 && arr[x][y+1] != 0) return false;
        if(y == 10 && arr[x+1][y] != 0 && arr[x-1][y] != 0 && arr[x][y-1] != 0) return false;
        if(arr[x+1][y] != 0 && arr[x-1][y] != 0 && arr[x][y+1] != 0 && arr[x][y-1] != 0) return false;
        else return true;
    }
    else return true;
}

int MapInput(int pos)
{
    int cur = 0, row, column;
    bool line;
    int X, Y;
    while(true)
    {
        cout << "Input NUMBER and LETTER" << endl;
        cin >> num >> let;
        if(Check(num, let) && arr[Converter(num)][(int)let[0]-x] == 0 && CheckDistance(Converter(num), (int)let[0]-x, pos))
        {
            X = Converter(num);
            Y = (int)let[0]-x;
                arr[X][Y] = pos;
                Show();
                row = X;
                column = Y;
                cur++;

               if(cur == pos){Show(); return 0;}

                    while(true){
                        cout << "Input NUMBER and LETTER" << endl;
                        cin >> num >> let;
                        if(Check(num, let) && arr[Converter(num)][(int)let[0]-x] == 0 && CheckDistance(Converter(num), (int)let[0]-x, pos))
                        {
                            X = Converter(num);
                            Y = (int)let[0]-x;
                                if( (X+1 == row || X-1 == row) && Y == column){
                                    arr[X][Y] = pos;
                                    cur++;
                                    Show();
                                    line = true;
                                    break;
                                }
                                if(X == row && (Y-1 == column || Y+1 == column)){
                                    arr[X][Y] = pos;
                                    cur++;
                                    Show();
                                    line = false;
                                    break;
                                }
                        }
                    }

                    if(cur == pos){Show(); return 0;}

                    while(true){
                        cout << "Input NUMBER and LETTER" << endl;
                        cin >> num >> let;
                        if(Check(num, let) && arr[Converter(num)][(int)let[0]-x] == 0 && CheckDistance(Converter(num), (int)let[0]-x, pos))
                        {
                            X = Converter(num);
                            Y = (int)let[0]-x;
                                if(line){
                                    if( (X+2 == row  || X-1 == row || X-2 == row || X+1 == row) && Y == column){
                                        arr[X][Y] = pos;
                                        cur++;
                                        Show();
                                        break;
                                    }
                                }
                                if(!line){
                                    if( (Y+2 == column || Y-1 == column || Y-2 == column || Y+1 == column) && X == row){
                                        arr[X][Y] = pos;
                                        cur++;
                                        Show();
                                        break;
                                    }
                                }
                        }
                    }

                    if(cur == pos){ Show(); return 0;}

                    while(true){
                        cout << "Input NUMBER and LETTER" << endl;
                        cin >> num >> let;
                        if(Check(num, let) && arr[Converter(num)][(int)let[0]-x] == 0 && CheckDistance(Converter(num), (int)let[0]-x, pos))
                        {
                            X = Converter(num);
                            Y = (int)let[0]-x;
                                if(line){
                                    if((X+3 == row || X-1 == row || X+2 == row || X-3 == row || X+1 == row || X-2 == row) && Y == column){
                                        arr[X][Y] = pos;
                                        cur++;
                                        Show();
                                        break;
                                    }
                                }
                                if(!line){
                                    if( (Y+3 == column  || Y-1 == column || Y+2 == column || Y-3 == column  || Y+1 == column || Y-2 == column) && X == row){
                                        arr[X][Y] = pos;
                                        cur++;
                                        Show();
                                        break;
                                    }
                                }
                        }
                    }
                    if(cur == pos){Show(); return 0;}
        }
    }
}

void PCmap(int level)
{
    int column, row, k = level , c(0);
    for(int i=1; i<=k; i++){
        column = rand() % y + 1;
        row = rand() % y + 1;
        if(PC_arr[column][row] != 1){
            PC_arr[column][row] = 1;
            c++;
        }
        else k++;
        if(c == level) break;
    }
}

bool string_check(string lvl)
{
    if(lvl.size() != 1) return false;
    for(char c = '1'; c<='5'; c++) if(c == lvl[0]) return true;
    return false;
}

int Choose_level()
{
    string level;
    int arr_lvl[5]={10, 12, 15, 20, 35};
    system("cls");
    Green; cout << "Level 1:  10 ships with 1 coordinate " << endl;
           cout << "Level 2:  12 ships with 1 coordinate " << endl;
    Blue;  cout << "Level 3:  15 ships with 1 coordinate " << endl;
           cout << "Level 4:  20 ships with 1 coordinate " << endl;
    Red;   cout << "Level 5:  35 ships with 1 coordinate " << endl;
    Blue;  cout << "To choose level push level number. Exm: '1'" << endl;

    while(true){
        cin >> level;
        if(string_check(level))
            break;
    }
    return arr_lvl[Converter(level) - 1];
}

void ShowPcDrown()
{
    Red;
    cout << "   ";
    for(char h = 'a'; h <= 'j'; h++) cout << (char)toupper(h) << " ";
    cout << endl;
    for(int i=1; i<=y; i++){
        bool cvx = true;
        for(int j=1; j<=y; j++){
            if(i < y && cvx){
                    Red;
                    cout << " " << i << " ";
                    cvx = false;
                }
                else if(i == y && cvx){
                    Red;
                    cout << i << " ";
                    cvx = false;
                }

            if(PC_drown[i][j] == '@') {Red;}
            else if(PC_drown[i][j] == 'X') {Green;}
            else {Blue;}
            cout << PC_drown[i][j] << " ";
        }
        cout << endl;
    }
    Blue;
}

void Express()
{
    Show();
    cout << "YOUR TURN TO ATTACK" << endl;
    cout << endl;
    cout << "COMPUTER SUNKEN BOATS MAP: " << endl;
    ShowPcDrown();
    cout << "Input NUMBER and LETTER to attack " << endl;
}

void Game()
{
    int pcX, pcY, Xb, Yb;
    Red;
    cout << "COMPUTER STARTS GAME" << endl;
    while(true){
        while(turn){
            Green;
            while(true){
                pcX = rand() % 10 + 1;
                pcY = rand() % 10 + 1;
                if(arr[pcX][pcY] != 9) break;
            }

            if(arr[pcX][pcY] == 0){
                arr[pcX][pcY] = 9;
                cout << "Computer missed!" << endl;
                system("pause");
                turn = false;
            }
            else{
                userSum++;

                if(arr[pcX][pcY] == 4){
                    arr[pcX][pcY] = 9;
                    cout << "The missile hit the Carrier!" << endl;
                }
                else if(arr[pcX][pcY] == 3){
                    arr[pcX][pcY] = 9;
                    cout << "The missile hit the Battleship!" << endl;
                }
                else if(arr[pcX][pcY] == 2){
                    arr[pcX][pcY] = 9;
                    cout << "The missile hit the Cruiser!" << endl;
                }
                else if (arr[pcX][pcY] == 1){
                    arr[pcX][pcY] = 9;
                    cout << "The missile hit the Destroyer!" << endl;
                }

                system("pause");

                if(userSum == lost){
                    cout << "COMPUTER WON!" << endl;
                    exit(0);
                }
            }
            Blue;
        }
        while(!turn){
            Express();
            while(true){
                cin >> num >> let;
                if(Check(num, let)){
                    Xb = Converter(num);
                    Yb = (int)let[0]-x;
                    if(PC_arr[Xb][Yb] == 1){
                        pcSum++;
                        PC_drown[Xb][Yb] = 'X';
                        if(pcSum == out){
                            Green; cout << "YOU WON!" << endl; Blue;
                            exit(0);
                        }
                        Express();
                        cout << "Your attack goes successfully!" << endl;
                    }
                    else{
                        cout << "You missed!" << endl;
                        PC_drown[Xb][Yb] = '@';
                        turn = true;
                        break;
                    }
                }
            }
        }

    }

}

void Input()
{
    for(int i=0; i<y; i++){
        if(a[i] == 4) cout << "Select 4 coordinates for Carrier" << endl;
        if(a[i] == 3) cout << "Select 3 coordinates for Battleship" << endl;
        if(a[i] == 2) cout << "Select 2 coordinates for Cruiser" << endl;
        if(a[i] == 1) cout << "Select 1 coordinates for Destroyer" << endl;
        MapInput(a[i]);
	}
}

int main()
{
    Setup();
	Show();
	Input();
    Show();
    system("pause");
    out = Choose_level();
    PCmap(out);
    Game();
	return 0;
}
