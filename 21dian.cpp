//文件名：作业二_21点游戏 
//21点游戏
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;
int player_get_a_card_num( int check[]);     //the player get a number between 0~51.
int computer_get_a_card_num(int check[]);		//the computer get a number between 0~51.
double   player_what_is_the_card(int check[]) ;    //the player gets the card connected to the number.
double get_the_first_two_card(int check[]);       //the player get the first two cards.
double player_whether_to_get_one_more_card(int check[]);     //the player make sure whether to get a more card.
double computer_stage(int check[]);          //the computer stage.
int player_cards(int check[]);           //the total cards of the player.
int computer_cards(int check[]);         //the total cards of the computer.
double   computer_what_is_the_card(int check[]) ;    //the computer gets the card connected to the number.

int main(){
	char answer;
	
	do{

		int check[52]={0};    //store the changed numbers.
		double sum1=0,sum2=0;	//the sum of the player's and computer's number. 
		double num_check;	

		cout<<"The stage of the players:";
		sum1+=get_the_first_two_card( check);
	
		while(true){
			if(sum1>21){
				cout<<endl<<"you are beated";
				break;
			} 
			
			if(num_check==0){
			break;
			}
			
			num_check=player_whether_to_get_one_more_card(check);
			sum1+=num_check;
		}
	
		while(true){
			if(sum1>21) break;
			
			if(sum2==0){
				cout<<"The stage of the computer:";	
			}
			
			if(sum2>21){
				cout<<endl<<"you win the game";
				break;
			}
				
			if(sum2<=sum1){
				sum2+=computer_stage(check);
			}
			
			if(sum2>sum1){
				if (sum2>21){
					cout<<endl<<"you win the game";
				}
				else cout<<endl<<"you are beated";
				break;
			}
		}
		
		cout<<endl<<"Do you want to continue(y or n)?";
		cin>>answer; 
		
		while(true){
			try{
				if(answer!= 'y' && answer != 'n')    throw 1;                      //judge whether the input is legal
			    else throw 0.5;
			}
			catch(int){
				cout << "Your input is ilegal! Please input y/n: ";
				cin >> answer;
			}
			catch(double){
				break;
			}
	    }
	
	}while(answer=='y');

	return 0;                        
}


int player_get_a_card_num(int check[]){

	int card_num;
	srand(time(NULL));
	do{
	card_num = rand() % 52;
	}while(check[card_num] == 1);
	check[card_num]=1;
	return card_num;	
	
}



double   player_what_is_the_card(int check[])                                            
{   
	int card_num;
	card_num=player_get_a_card_num( check);

		switch(card_num % 13){
			case 1:   	 return 1;break;
			case 0:    	 return 0.5;break;
			case 11:     return 0.5;break;
			case 12:     return 0.5;break;
			default:     return card_num % 13;
		}	
		
}



double get_the_first_two_card(int check[]){
	
	double sum=0;
	sum+=player_what_is_the_card(check) ;
	sum+=player_what_is_the_card(check) ;
	cout<<endl;
	int i;
    player_cards(check);
	return sum;
	
}

double player_whether_to_get_one_more_card(int check[]){
	char answer;
	double num1;
	cout<<endl<<"Do you want one more card(y or n)?";
	cin>>answer;
	
	while(true){
			try{
				if(answer!= 'y' && answer != 'n')    throw 1;                      //judge whether the input is legal
			    else throw 0.5;
			}
			catch(int){
				cout << "Your input is ilegal! Please input y/n: ";
				cin >> answer;
			}
			catch(double){
				break;
			}
	    }
	
	if (answer=='y'){
		num1= player_what_is_the_card(check);
		player_cards( check);
		return num1;
	}
	if (answer=='n'){
		return 0;
	}
}




int computer_get_a_card_num(int check[]){

	int card_num;
	srand(time(NULL));
	do{
	card_num = rand() % 52;
	}while((check[card_num] == 1)||(check[card_num] == 2));
	check[card_num]=2;
	return card_num;	
	
}

double   computer_what_is_the_card(int check[])                                            
{   
	int card_num;
	card_num=computer_get_a_card_num( check);

		switch(card_num % 13){
			case 1:    	 return 1;break;
			case 0:    	  return 0.5;break;
			case 11:       return 0.5;break;
			case 12:      return 0.5;break;
			default:     return card_num % 13;
		}	
			
}

double computer_stage(int check[]){
	
	double num2=0;
	num2+=computer_what_is_the_card(check);
	computer_cards(check);
	return num2;
	
}

int player_cards(int check[]){
	int i=0;
	cout<<"The cards of the player:"<<endl;
	for(i=0;i<52;++i){
		if(check[i]==1){
		switch(i/ 13){
    	    case 0: cout << "spade "<<" ";    break; 
    		case 1: cout << "heart "<<" ";    break;
    		case 2: cout << "club " <<" ";    break;
    		default: cout << "diamond "<<" ";    break;
		}
		switch(i % 13){
			case 1:    cout << "A  "<<" ";	 break;
			case 0:    cout << "K  "<<" ";	  break;
			case 11:    cout << "J  "<<" ";    break;
			case 12:    cout << "Q  "<<" ";    break;
			default:    cout << i % 13;
	
		}
			cout<<"  ";
	}
	}
}

int computer_cards(int check[]){
	int i=0;
	cout<<endl<<"The cards of the computer:"<<endl;
	for(i=0;i<52;++i){
		if(check[i]==2){
		switch(i/ 13){
    	    case 0: cout << "spade "<<" ";    break; 
    		case 1: cout << "heart "<<" ";    break;
    		case 2: cout << "club " <<" ";    break;
    		default: cout << "diamond "<<" ";    break;
		}
		switch(i % 13){
			case 1:    cout << "A  "<<" ";	 break;
			case 0:    cout << "K  "<<" ";	  break;
			case 11:    cout << "J  "<<" ";    break;
			case 12:    cout << "Q  "<<" ";    break;
			default:    cout << i % 13;
		
		}
		cout<<"  ";
	}
	}
}

