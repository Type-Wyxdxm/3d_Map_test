/*
Code List:
change x y z : 修改 Pos(x,y,z) 的值 (W->. .->W) 
set x y z c : 修改 Pos(x,y,z) 的值为 c 
fill_ch x1 y1 z1 x2 y2 z2 : 以 change 相同方式修改 Pos(x1,y1,z1)到 Pos(x2,y2,z2) 范围内的值 
fill x1 y1 z1 x2 y2 z2 c : 修改 Pos(x1,y1,z1)到 Pos(x2,y2,z2) 范围内的值为 c 
goto z : 切换显示 Z=z 面 
end : 结束程序 
export name : 将地图导出至文件 name 
import name : 从文件 name 导入文件 
*/

#include <iostream>
#include <fstream>
using namespace std;

char mp[15][15][15];
int posz=1;

int main(){
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			for(int k=1;k<=10;k++){
				mp[i][j][k] = 'W';
			}
		}
	}
	string code="";
	while(code!="end"){
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++){
				cout << mp[i][j][posz];
			}
			cout << endl;
		}
		cout << "Posz:" << posz << endl;
		
		cin >> code;
		if(code=="") continue;
		if(code=="change"){
			int x,y,z;
			cin >> x >> y >> z;
			mp[x][y][z]=(mp[x][y][z]=='W' ? '.' : 'W');
			continue;
		}
		if(code=="set"){
			int x,y,z;
			char c;
			cin >> x >> y >> z >> c;
			mp[x][y][z]=c;
			continue;
		}
		if(code=="goto"){
			int z;
			cin >> z;
			posz=z;
			continue;
		}
		if(code=="export"){
			string name;
			cin >> name;
			name = name;
			ofstream ofs(name.c_str());
			ofs.write("",0); 
			for(int i=1;i<=10;i++){
				for(int j=1;j<=10;j++){
					for(int k=1;k<=10;k++){
						ofs << mp[i][j][k];
					}
					ofs << endl;
				}
				ofs << endl;
			}
		}
		if(code=="import"){
			string name;
			cin >> name;
			ifstream ifs(name.c_str());
			for(int i=1;i<=10;i++){
				for(int j=1;j<=10;j++){
					for(int k=1;k<=10;k++){
						ifs >> mp[i][j][k];
					}
				}
			}
		}
		if(code=="fill_ch"){
			int x1,y1,z1,x2,y2,z2;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			for(int i=x1;i<=x2;i++){
				for(int j=y1;j<=y2;j++){
					for(int k=z1;k<=z2;k++){
						mp[i][j][k] = (mp[i][j][k]=='W' ? '.' : 'W');
					}
				}
			}
		}
		if(code=="fill"){
			int x1,y1,z1,x2,y2,z2;
			char c;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> c;
			for(int i=x1;i<=x2;i++){
				for(int j=y1;j<=y2;j++){
					for(int k=z1;k<=z2;k++){
						mp[i][j][k] = c;
					}
				}
			}
		}
		
		
	}
} 
