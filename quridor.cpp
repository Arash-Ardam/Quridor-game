#include<iostream>
#include<iomanip>
#include<cstring>
#include<windows.h>
using namespace std;
char wall[9][9];
char wallv[9][9];
int x2=4,y2=8,x=4,y=0;

void bord1(int i1,int i2,int j1,int j2, int l , int k, int f, int g){

	char khone[9][9];
cout<<endl;
cout<<setw(5)<<1;
for(int x=1;x<9;x++)
cout<<setw(4)<<x+1;
cout<<endl;


for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
		khone[i][j]='*';
	}
}
for(int z=0;z<9;z++){
	for(int r=0;r<9;r++){
		wall[z][r]=' ';
	}
}
	for(int z=0;z<9;z++){
for(int r=0;r<9;r++){
		wallv[z][r]=' ';
	
			}
}

khone[i1][j1]='A';
khone[i2][j2]='B';
for(int c=0;c<9;c++){
	cout<<endl<<c+1<<setw(4);
	for(int v=0;v<9;v++){
		
		if(v==0)
		cout<<setw(4)<<khone[c][v]<<setw(2)<<wallv[c][v];
		else 
		cout<<setw(2)<<khone[c][v]<<setw(2)<<wallv[c][v];
			if(v==8)
		cout<<endl;}
		for(int t=0;t<9;t++){
			if(t==0)
				cout<<setw(5)<<wall[t][c];
				else
				cout<<setw(4)<<wall[t][c];
				if(t==8)
					cout<<endl;
		}
}
}

void bord(int i1,int i2,int j1,int j2, int l , int k, int f, int g){

	char khone[9][9];
cout<<endl;
cout<<setw(5)<<1;
for(int x=1;x<9;x++)
cout<<setw(4)<<x+1;
cout<<endl;


for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
		khone[i][j]='*';
	}
}

wall[l][k]='=';
wall[l+1][k]='=';
wallv[g][f]= '|';

khone[i1][j1]='A';
khone[i2][j2]='B';
for(int c=0;c<9;c++){
	cout<<endl<<c+1<<setw(4);
	for(int v=0;v<9;v++){
		if(v==0)
		cout<<setw(4)<<khone[c][v]<<setw(2)<<wallv[c][v];
		else 
		cout<<setw(2)<<khone[c][v]<<setw(2)<<wallv[c][v];
			if(v==8)
		cout<<endl;}
		for(int t=0;t<9;t++){
			if(t==0)
				cout<<setw(5)<<wall[t][c];
				else
				cout<<setw(4)<<wall[t][c];
				if(t==8)
					cout<<endl;
		}
}
}


struct order{
	int wall;
	int exit;
	int move;
	
};


int main(){

 int plus=0,sum=0;
order p1,p2;
p1.wall=10;
p2.wall=10;
while(true){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
cout<<"1 - start game"<<endl;

cout<<"2 - exit"<<endl;

int order_1;

cin>>order_1;

if(order_1==2){
	return 0;
}


if(order_1==1)
bord(0,8,4,4,'\n','\n','\n','\n');

cout<<endl;

for(int i=0;;i++){

jump:
 cout<<"1- Add Wall"<<endl<<"2- Move"<<endl<<"3- exit to menu"<<endl;
cout<<"p1 enter your order: ";
int order;
cin>>order;


if(order==3){
break;
}
string h,h2;

int l='\n',k='\n',g='\n',f='\n';
if(order==2){
	cout<<"enter your destination p1(left/right/up/down): "<<endl;

	cin>>h;
	if(x==x2 && y==y2-1 && h=="down" && wall[x][y+2]!='='){
		y=y+2;
		if(y>8){
			y=y-2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x==x2 && y==y2+1 && h=="up" && wall[x][y-2]!='='){
		y=y-2;
		if(y<0){
			y=y+2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x==x2-1 && y==y2 &&h=="right" && wallv[y][x+2]!='|'){
		x=x+2;
		if(x>8){
			x=x-2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x==x2+1 && y==y2 && h=="left" && wallv[y][x-2]!='|'){
		x=x-2;
		if(x<0){
			x=x+2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x==x2 && y==y2-1 && h=="down" && wall[x][y+2]=='='){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"You cant jump"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		goto jump;
	}
	else if(x==x2 && y==y2+1 && h=="up" && wall[x][y-2]=='='){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"You cant jump"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		goto jump;
	}
	else if(x==x2-1 && y==y2 &&h=="right" && wallv[y][x+2]=='|'){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"You cant jump"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		goto jump;
	}
	else if(x==x2+1 && y==y2 && h=="left" && wallv[y][x-2]=='|'){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout<<"You cant jump"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump;
	}
	
	else{
	
	if (wall[x][y]=='=' && h=="down"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
cout<<"There is a wall here"<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
goto jump;
}
else if(wall[x][y+1]=='=' && h=="up"){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout<<"There is a wall here"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump;
}
else if(wallv[y][x-1]=='|' && h=="left"){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout<<"There is a wall here"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump;
}
else if(wallv[y][x]=='|' && h=="right"){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout<<"There is a wall here"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump;
}
else{

	if(h=="left")
		x=x-1;
else if(h=="right")
x=x+1;
else if(h=="up")
y=y-1;
else if(h=="down")
y=y+1;

 if(x<0 || x>8 || y<0 || y>8 ){
 if(x<0)
 x=x+1;
 if(x>8)
 x=x-1;
 if(y<0)
 y=y+1;
 if(y>8)
 y=y-1;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	cout<<"out of range"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
goto jump;
	
}
else
	bord(y,y2,x,x2,l,k,g,f);
}	
	}
}
		if(y==8){
		cout<<"The first player wins"<<endl;
		return 0;
	}
int c,d;
string direction;
 if(order==1){
 	cout<<"Enter your wall place and Type of wall placement('start-x start-y Horizontal/Vertical'):";
cin>>c>>d>>direction;
if(direction=="Horizontal"){
l=c-1;
k=d-1;
}
else if(direction=="Vertical"){
f=c-1;
g=d-1;
}
bord(y,y2,x,x2,l,k,f,g);
plus++;
if(plus>10){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"The walls are finished"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	goto jump;

}	
}


jump2:	
cout<<"1- Add Wall"<<endl<<"2- Move"<<endl<<"3- exit to menu"<<endl;
cout<<"p2 enter your order: ";
int order2;
cin>>order2;

if(order2==3){
break;
}

if(order2==2){
	cout<<"enter your destination p2(left/right/up/down): "<<endl;
	
	cin>>h2;
		if(x2==x && y2==y-1 && h2=="down" && wall[x2][y2+2]!='='){
		y2=y2+2;
		if(y2>8){
			y2=y2-2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump2;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x2==x && y2==y+1 && h2=="up" && wall[x2][y2-2]!='='){
		y2=y2-2;
			if(y2<0){
			y2=y2+2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump2;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x2==x-1 && y2==y &&h2=="right" && wallv[y2][x2+2]!='|'){
		x2=x2+2;
			if(x2>8){
			x2=x2-2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump2;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x2==x+1 && y2==y && h2=="left" && wallv[y2][x2-2]!='|'){
		x2=x2-2;
			if(x2<0){
			x2=x2+2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"Out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			goto jump2;
		}
		else
			bord(y,y2,x,x2,l,k,g,f);
	}
	else if(x2==x && y2==y-1 && h2=="down" && wall[x2][y2+2]=='='){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"You cant jump"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		
		goto jump2;
	}
	else if(x2==x && y2==y+1 && h2=="up" && wall[x2][y2-2]=='='){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"You cant jump"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		goto jump2;
	}
	else if(x2==x-1 && y2==y &&h2=="right" && wallv[y2][x2+2]=='|'){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"You cant jump"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		goto jump2;
	}
	else if(x2==x+1 && y2==y && h2=="left" && wallv[y2][x2-2]=='|'){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"You cant jump"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump2;
	}
	else{
	
	
	if (wall[x2][y2]=='=' && h2=="down"){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"There is a wall here"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

goto jump2;
}
else if(wall[x2][y2-1]=='=' && h2=="up"){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"There is a wall here"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump2;
}
else if(wallv[y2][x2-1]=='|' && h2=="left"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"There is a wall here"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump2;
}
else if(wallv[y2][x2]=='|' && h2=="right"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout<<"There is a wall here"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	goto jump2;
}
else{

		if(h2=="left")
		x2=x2-1;
else if(h2=="right")
x2=x2+1;
else if(h2=="up")
y2=y2-1;
else if(h2=="down")
y2=y2+1;

	if(x2<0 || x2>8 || y2<0 || y2>8){
 if(x2<0)
 x2=x2+1;
 if(x2>8)
 x2=x2-1;
 if(y2<0)
 y2=y2+1;
 if(y2>8)
 y2=y2-1;
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout<<"out of range"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

goto jump2;
}
else
bord(y,y2,x,x2,l,k,f,g);
}
}
}
if(y2==0){
		cout<<"The second player wins"<<endl;
		return 0;
}
int i2,j2;
string direction2;
 
  if(order2==1){
 	cout<<"Enter your wall place and Type of wall placement2('start-x2 start-y2 Horizontal/Vertical'):";
cin>>i2>>j2>>direction2;
if(direction2=="Horizontal"){
l=i2-1;
k=j2-1;

}
else if(direction2=="Vertical"){
	f=i2-1;
	g=j2-1;
}

bord(y,y2,x,x2,l,k,f,g);
sum++;
if(sum>10){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout<<"The walls are finished"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	
goto jump2;
}	
}
}

	}


}
