
   #include<iostream>
   #include<bits/stdc++.h>
    using namespace std;
     struct node{
         int data;
          struct node* ptr_1;
          struct node* ptr_2;
     };  

           struct node* reverse_linked_list(int);


          int first_linked_list(struct node* fun_previous_ptr_1){
                   int number_1=0;
                    struct node* reverse_ptr_1=fun_previous_ptr_1;
                      while(reverse_ptr_1!=NULL){
                            number_1=number_1*10+reverse_ptr_1->data;
                            reverse_ptr_1=reverse_ptr_1->ptr_1;
                      }     
            return number_1;
          }
          int second_linked_list(struct node* fun_previous_ptr_2){
                   int number_2=0;
                    struct node* reverse_ptr_2=fun_previous_ptr_2;
                      while(reverse_ptr_2!=NULL){
                            number_2=number_2*10+reverse_ptr_2->data;
                            reverse_ptr_2=reverse_ptr_2->ptr_1;
                      }     
            return number_2;
          }
     int main(){
          struct node* start_1=NULL;
          struct node* start_2=NULL;

          struct node* end_1=NULL;
          struct node* end_2=NULL;

          struct node* previous_ptr_1=NULL;
          struct node* previous_ptr_2=NULL;
                
           int size_1;
            cout<<"enter the number of node of first linked list: ";
            cin>>size_1;
 
            //input in first linked list
             for(int i=1;i<=size_1;i++){
                 struct node* new_node_1=(struct node*)malloc(sizeof(struct node));
                   cout<<"enter the value in first linked list in node "<<i<<": ";
                   cin>>new_node_1->data;
                    new_node_1->ptr_1=NULL;
                    new_node_1->ptr_2=NULL;

                    if(start_1==NULL){
                        start_1=new_node_1;
                         end_1=new_node_1;
                         previous_ptr_1=new_node_1;
                    }
                     else{
                        end_1->ptr_2=new_node_1;
                        end_1=new_node_1;
                         end_1->ptr_1=previous_ptr_1;
                         previous_ptr_1=new_node_1;
                     }
             }
              cout<<endl<<"first linked list \n";
                 struct node* first_ptr=start_1;
                 while(first_ptr!=NULL){
                          cout<<first_ptr->data<<" ";
                           first_ptr=first_ptr->ptr_2;
                 }

                 cout<<endl<<endl; 
                  int size_2;
            cout<<"enter the number of node of second linked list: ";
            cin>>size_2;

            //input in second linked list
             for(int i=1;i<=size_2;i++){
                 struct node* new_node_2=(struct node*)malloc(sizeof(struct node));
                   cout<<"enter the value in second linked list in node "<<i<<": ";
                   cin>>new_node_2->data;
                    new_node_2->ptr_1=NULL;
                    new_node_2->ptr_2=NULL;

                    if(start_2==NULL){
                        start_2=new_node_2;
                         end_2=new_node_2;
                         previous_ptr_2=new_node_2;
                    }
                     else{
                        end_2->ptr_2=new_node_2;
                        end_2=new_node_2;
                         end_2->ptr_1=previous_ptr_2;
                         previous_ptr_2=new_node_2;
                     }
             }
              cout<<endl<<"second linked list \n";
                 struct node* second_ptr=start_2;
                 while(second_ptr!=NULL){
                          cout<<second_ptr->data<<" ";
                           second_ptr=second_ptr->ptr_2;
                 }   
                 cout<<endl;
              int x_1= first_linked_list(previous_ptr_1);
              int x_2= second_linked_list(previous_ptr_2);
              cout<<"reverse number of first linked list: "<<x_1<<endl;
              cout<<"reverse number of second linked list: "<<x_2<<endl;
             
                int sum_reverse_number=x_1+x_2;
                  cout<<endl<<"sum of reverse two linked list "<<sum_reverse_number;
                struct node* new_reverse=reverse_linked_list(sum_reverse_number);

                 cout<<endl<<"new reverse linked list"<<endl;
                   struct node* reverse_new_list=new_reverse;
                     while(reverse_new_list!=NULL){
                          cout<<reverse_new_list->data<<" ";
                          reverse_new_list=reverse_new_list->ptr_2;
                     }
        return 0;
     }

          struct node* reverse_linked_list(int number){
                        struct node* new_reverse_start=NULL;
                        struct node* new_reverse_end=NULL;
                        struct node* new_reverse_previous=NULL;

                             int remainder;     
                        while(number>0){
                           remainder=number%10;
                             struct node* new_reverse_linked=(struct node*)malloc(sizeof(struct node));
                             new_reverse_linked->data=remainder;
                             new_reverse_linked->ptr_1=NULL;  
                             new_reverse_linked->ptr_2=NULL;  

                             if(new_reverse_start==NULL){
                                new_reverse_start=new_reverse_linked;
                                new_reverse_end=new_reverse_linked;
                                new_reverse_previous=new_reverse_linked;
                             }
                             else{
                                new_reverse_end->ptr_2=new_reverse_linked;
                                new_reverse_end=new_reverse_linked;
                                 new_reverse_end->ptr_1=new_reverse_previous;
                                 new_reverse_previous=new_reverse_linked;
                             }
                             number=number/10;
                            }
            return new_reverse_start;
          }