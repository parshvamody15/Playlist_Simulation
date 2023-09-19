#include<iostream>
#include<string.h>

using namespace std;
//Creation of node for playlist
struct node{
	int index;
	string songname;
	struct node*next;
	struct node*prev;
};

int printlist(node *&head)//prints the playlist
{
	if(head==NULL){
		cout<<"Playlist is empty!!\n";
		return 0;
	}
	else{
		struct node*temp=head;
		while(temp->next!=head){
			cout<<temp->index<<".)"<<temp->songname<<" "<<endl;
			temp=temp->next;
		}
		cout<<temp->index<<".)"<<temp->songname<<" "<<endl;
		return 1;
	}
}

void searchAndAdd(int c,node *&head_playlist,node *&head_list)
{
	int flag=0;
	struct node*temp_playlist=head_playlist;
	struct node*temp_list=head_list;
	struct node*temp3=new struct node;
	
	while(temp_playlist->next!=head_playlist){
			if (temp_playlist->index==c)
			{
				if (head_list==NULL)
				{
					temp3->index=1;
					temp3->songname=temp_playlist->songname;
					head_list=temp3;
					temp3->next=temp3;
					temp3->prev=temp3;
					flag=1;
					break;
					
				}
				else 
				{
					temp3->index=temp_list->prev->index+1;
					temp3->songname=temp_playlist->songname;
					temp_list->prev->next=temp3;
					temp3->prev=temp_list->prev;
					temp3->next=temp_list;
					temp_list->prev=temp3;
					//temp3->prev=temp_list->prev->prev;
					flag=1;
					//printlist(head_list);
					break;
				}
				
			}
			else
				temp_playlist=temp_playlist->next;
		}
		if (temp_playlist->next==head_playlist && temp_playlist->index==c && flag==0)
		{
			
			if (head_list==NULL)
			{
				temp3->index=1;
				temp3->songname=temp_playlist->songname;
				head_list=temp3;
				temp3->next=temp3;
				temp3->prev=temp3;
				flag=1;
				
				
			}
			else 
			{
				temp3->index=temp_list->prev->index+1;
				temp3->songname=temp_playlist->songname;
				temp_list->prev=temp3;
				temp3->next=temp_list;
				temp_list->prev->prev=temp3;
				temp3->prev=temp_list->prev->prev;
				flag=1;
			
			}
			
		}
		if (flag==0)
			cout<<"Wrong Index!"<<endl;
		else
		{
			cout<<"Song has been added successfully!"<<endl;
			cout<<"song added:"<<temp3->songname<<endl;

		}
		
}


void deleting(int ele,struct node*&head)//use function wherever needed
{
	//printlist(head);
	//deleting node from playlist
	struct node*temp=head;
	int flag=0;
	if(temp==NULL){
		cout<<"Playlist is empty!!\n";
	}
	else if(temp->index==ele){
		if(temp->next==head)
		{
			head=NULL;
			cout<<"Playlist is now empty!"<<endl;
		}
		else
		{
			temp->next->prev=temp->prev;
		head=temp->next;
		temp->prev->next=temp->next;
		flag=1;
		cout<<"Song Deleted!"<<endl;
		int i=1;
			temp=head;
			while(temp->next!=head)
			{
				temp->index=i;
				i++;
				temp=temp->next;
			}
			temp->index=i;
		}
		
	}
	else{
		while(temp->next!=head){
			if(temp->index==ele){
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				flag=1;
				break;
			}
			else{
				temp=temp->next;
			}
		}
		if(temp->index==ele){
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			flag=1;
		}
		int i=1;
		if (flag==1)
		{
			cout<<"Song Deleted!"<<endl;
			temp=head;
			while(temp->next!=head)
			{
				temp->index=i;
				i++;
				temp=temp->next;
			}
			temp->index=i;
		}
			
		else
			cout<<"Song Not Found!"<<endl;

	}

}

void list_to_playlist(node *&head_playlist)//choose songs from our list and add to a circular doubly ll
{
	int a,b,x;
    //char temp[100];
    int y=1;
    string songs[]={"Udd Gaye by Ritviz",
    "Tum Ho Toh by Farhan Akhtar",
    "Tera Hone Laga Hoon by Atif Aslam",
    "Tum Ho by Mohit Chauhan",
    "Ajab Si by KK",
    "Tujhe Bhula Diya by Mohit Chauhan",
    "Subhanallah by Pritam",
    "Mere Yaara by Arijit Singh",
    "Tu Aakhe Dekhle by King",
    "You by Armaan Malik",
    "Pee Loon by Pritam",
    "Humrah by Sachet Tandon",
    "SeÃ±orita by Farhan Akhtar",
    "Blue Eyes by Yo Yo Honey Singh",
    "Pehla Nasha by Udit Narayan",
    "Aadat by Atif Aslam",
    "Criminal by Vishal Dadlani",
    "Humsafar by Akhil Sachdeva",
    "Falak Tak by Vishal-Shekhar",
    "Ishq Sufiyana by Sunidhi Chauhan",
    "Shubhaarambh by Amit Trivedi",
    "Aye Khuda by Salim Merchant",
    "Spaceship by AP Dhillon",
    "O Mere Dil Ke Chein by Sanam",
    "Tera Zikr by Darshan Raval"};
    

    
    cout<<"Enter the song number:";
    cin>>b;
    if(b>25 || b<1)
    	cout<<"invalid index"<<endl;
    else
    {
	    struct node *newnode=new struct node;
	    struct node *temp=head_playlist;
	    if(temp==NULL)
	    {
	    	newnode->index=1;
			newnode->songname=songs[b-1];
			head_playlist=newnode;
			newnode->next=newnode;
			newnode->prev=newnode;
			
		}
		else
		{
			temp=temp->prev;
			newnode->index=temp->index+1;
			newnode->songname=songs[b-1];
			temp->next->prev=newnode;
	    	temp->next=newnode;
			newnode->next=head_playlist;
			newnode->prev=temp;
		}  
	}
       
}
void add_to_playlist(struct node*&head)//user enters songs to add to a circular doubly ll
{
	struct node *temp=head;
	struct node *newnode=new struct node;
	string songname2;
	cout<<"Enter songname:";
	//getline(cin,songname2);
	cin>>songname2;
	newnode->songname=songname2;
	if(temp==NULL)
	{
		head=newnode;
		newnode->index=1;
		newnode->next=newnode;
		newnode->prev=newnode;
	}
	else
	{
		temp=temp->prev;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
		newnode->next=head;
		newnode->index=temp->index+1;
		
	}
}

void playing_playlist(struct node* &head,struct node* &current_node)//plays from playlist, includes, 1.play on shuffle 2.next 3.prev 4.choose to start playing from 5.pause
{
	int choice2,play=0;
	do
	{
			cout<<"1.)Next song\n2.)Previous song\n3.)Play/Pause\n4.)Choose the starting song from the playlist\n5.)Exit"<<endl;
			cin>>choice2;
			
		 	if (choice2==1)
			{
				current_node=current_node->next;
				if (current_node==head)
				cout<<"\nBack to the start of the playlist\n\nCurrently playing: "<<current_node->songname<<endl;
				else
				cout<<"\nCurrently playing: "<<current_node->songname<<endl;
				play=1;
			}
			else if (choice2==2)
			{
				current_node=current_node->prev;
				if (current_node==head)
				cout<<"\nBack to the start of the playlist\n\nCurrently playing: "<<current_node->songname<<endl;
				else
				cout<<"\nCurrently playing: "<<current_node->songname<<endl;
				play=1;
			}
			else if (choice2==3)
			{
				if (play==0)
				{
					cout<<"PLAY\nCurrently playing: "<<current_node->songname<<endl;
					play=1;
				}
				else
				{
					cout<<"PAUSE"<<endl;
					play=0;
				}
			}
			else if (choice2==4)
			{
				struct node* temp=head;
				cout<<"Current playlist:"<<endl;
				printlist(head);
				cout<<"\nWhich song would you like to start from?\nEnter its number:";
				int num,flag=0;
				cin>>num;
				if (temp->index==num)
				{
					current_node=temp;
					cout<<"Starting the playlist from "<<num;
					cout<<"\nCurrently playing: "<<current_node->songname<<endl;
					flag=1;
				}
				else
				{
					temp=temp->next;
					while (temp!=head)
					{
						if (temp->index==num)
						{
							current_node=temp;
							cout<<"Starting the playlist from "<<num;
							cout<<"\nCurrently playing: "<<current_node->songname<<endl;
							flag=1;
							break;
						}
						else
						temp=temp->next;
					}
				}
				if (flag==0)
				cout<<"INVALID NUMBER ENTERED!"<<endl;
				play=1;
			}
			else if(choice2==5)
			break;
			else
			cout<<"INVALID CHOICE!"<<endl;
	}while(choice2!=5);
}

void make_new_list(struct node *&head_playlist,struct node *&head_list)//display playlist and input required songs for current playing, put do while loop inside
{
	int c;
	cout<<"\nYour playlist is displayed below:"<<endl;
	int n=printlist(head_playlist);//Print already made playlist using print function or by traversal of original doubly linked list
	//Use function to add data nodes from first linked list to second linked list which is the current queue only when printlist() returns 1
	if(n==1){
	//struct node*temp2=new struct node;
	do{
		
		cout<<"Select the index of song you want to add your list,enter -1 to exit:\n";
		
	//	int c;//choice of index of song name
		cin>>c;
		if(c==-1)
			break;
		searchAndAdd(c,head_playlist,head_list);
	}while(c!=-1 );
	}

}

void playing_new_list(struct node* &head_list,struct node* &current_node)//plays from new list, includes, 1.play on shuffle 2.next 3.prev  4.remove from new list 5.pause 6.shift songs in playing order
{
	int choice_list,check_playing=0;
	int shift,position,flag_shift=0,flag_position=0,i=0;
	do
	{
			cout<<"\n";
			cout<<"1.Play next\n2.Play previous\n3.Play/Pause\n4.Remove a song from the list\n5.Shift a song in the list\n6.View list\n7.Exit"<<endl;
			cin>>choice_list;
			if (choice_list==1)
			{
				current_node=current_node->next;
				if (current_node==head_list)
				cout<<"\nBack to the start of the list\nCurrently playing: "<<current_node->songname<<endl;
				else
				cout<<"\nCurrently playing: "<<current_node->songname<<endl;
				check_playing=1;
			}
			else if (choice_list==2)
			{
				current_node=current_node->prev;
				if (current_node==head_list)
				cout<<"\nBack to the start of the list\n\nCurrently playing: "<<current_node->songname<<endl;
				else
				cout<<"\nCurrently playing: "<<current_node->songname<<endl;
				check_playing=1;
			}
		
			else if (choice_list==3)
			{
				if (check_playing==0)
				{
					cout<<"PLAY\nCurrently playing: "<<current_node->songname<<endl;
					check_playing=1;
				}
				else
				{
					cout<<"PAUSE"<<endl;
					check_playing=0;
				}
			}
			else if(choice_list==4)
			{
				int del;
				int n=printlist(head_list);
				if(n==1)
				{
					cout<<"Enter the song to be deleted(index number)";
					cin>>del;
					deleting(del,head_list);
				}
				check_playing=1;
			}
			
			else if(choice_list==5)
			{
				string swap;
				
				struct node* temp=head_list;
				printlist(head_list);
				
				cout<<"Enter number of song you wish to shift."<<endl;
				cin>>shift;
				cout<<"Enter position you wish to shift it to."<<endl;
				cin>>position;
				struct node* temp1=head_list;
				struct node* temp2=head_list;
				while(temp1->next!=head_list)
				{
					if(temp1->index==shift)
					{
						flag_shift=1;
						break;
					}
					else
					temp1=temp1->next;
				}
				if(flag_shift==0 && temp1->index==shift)
				{
					//cout<<"entered";
					flag_shift=1;
				}
					
				if(flag_shift==0)
				{
					cout<<"Song number does not exist."<<endl;
					continue;
				}
				
				while(temp2->next!=head_list)
				{
					if(temp2->index==position)
					{
						flag_position=1;
						break;
					}
					else
					temp2=temp2->next;
				}
				if(flag_position==0 && temp2->index==position)
				flag_position=1;
				if(flag_position==0)
				{
					cout<<"Enter valid position."<<endl;
					continue;
				}
				
				if(flag_shift==1 && flag_position==1)
				{
					swap=temp1->songname;
					temp1->songname=temp2->songname;
					temp2->songname=swap;
				}
			}
			else if(choice_list==6)
			{
				cout<<endl;
				printlist(head_list);
			}
			else if(choice_list==7)
			break;
			else
			cout<<"INVALID CHOICE!"<<endl;
	}while(choice_list!=7);

}
int main()
{
	struct node*list_head=NULL;
	struct node*playlist_head=NULL;

	cout<<"\t\t\t\t\t\t\tWELCOME TO YOUR VERY OWN MUSIC PLAYER!"<<endl;
	string songs[]={"Udd Gaye by Ritviz","Tum Ho Toh by Farhan Akhtar","Tera Hone Laga Hoon by Atif Aslam","Tum Ho by Mohit Chauhan","Ajab Si by KK","Tujhe Bhula Diya by Mohit Chauhan","Subhanallah by Pritam","Mere Yaara by Arijit Singh","Tu Aakhe Dekhle by King","You by Armaan Malik","Pee Loon by Pritam","Humrah by Sachet Tandon","Señorita by Farhan Akhtar","Blue Eyes by Yo Yo Honey Singh","Pehla Nasha by Udit Narayan","Aadat by Atif Aslam","Criminal by Vishal Dadlani","Humsafar by Akhil Sachdeva","Falak Tak by Vishal-Shekhar","Ishq Sufiyana by Sunidhi Chauhan","Shubhaarambh by Amit Trivedi","Aye Khuda by Salim Merchant","Spaceship by AP Dhillon","O Mere Dil Ke Chein by Sanam","Tera Zikr by Darshan Raval"};
	cout<<"Pre loaded songs are: \n";
    for(int i=0;i<25;i++)
    {
        cout<<i+1<<".)"<<songs[i]<<"\n";
	}
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	int choice,flag_making_playlist=0;
	do{
	cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"1:Choose songs from the given list\n2:Add your own song\n3:Delete from playlist\n4:Proceed to using your playlist\n5:View playlist\n6:Exit program\nEnter your choice:";
		cin>>choice;
		if(choice==1)
		{
			list_to_playlist(playlist_head);
			flag_making_playlist=1;
		}
		else if(choice==2)
		{
			add_to_playlist(playlist_head);
			flag_making_playlist=1;
		}
		else if(choice==3)
		{
			int del;
			int n=printlist(playlist_head);
			if(n==1)
			{
				cout<<"Enter the song to be deleted(index number)";
			cin>>del;
			deleting(del,playlist_head);
			}
			
		}
		else if(choice==4)
		{
			int c;
			if(flag_making_playlist==0)
			{
				cout<<"Let's make the playlist first!"<<endl;
				continue;
			}
				struct node*current_node_playlist=playlist_head;
				struct node*current_node_list=list_head;
			do
			{
				cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"1:Play the entire playlist\n2:Add songs from playlist to a seperate playing list\n3:Go back and edit playlist\nEnter your choice:";
				cin>>c;
				if(c==1)
				{
					playing_playlist(playlist_head,current_node_playlist);	
				}
				else if(c==2)
				{
					make_new_list(playlist_head,list_head);
					struct node*current_node_list=list_head;
					if(list_head==NULL)
						cout<<"list is empty!"<<endl;
					else
					{
						cout<<"\nPlaying from new list\n";
						playing_new_list(list_head,current_node_list);
					}
					
				}
			}while(c!=3);
			
		}
		else if(choice==5)
		{
			printlist(playlist_head);
		}
		else if(choice>6 || choice<1)
		{
			cout<<"wrong choice entered"<<endl;
		}
		
	}while(choice!=6 || flag_making_playlist==0) ;
	
}
