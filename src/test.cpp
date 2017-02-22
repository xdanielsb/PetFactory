
/*
 * In this example I show how to create  a hash_table, 
 * insert some items and after that show that linked list. 
 * Finally this is write in disk and read from disk, like a
 * RAM memory.
 */

inline void example_creating_hash_table(){
    hash_table  a = get_hash_table();  //This create the hash table from scratch
                                       //In another situation we need to load first
                                       //Just a example
    int hash = 15; 
    node * linked  = a[hash];    
    insert_linked_list(linked, 231);
    insert_linked_list(linked, 543);
    insert_linked_list(linked, 429);

    a[hash] = linked; //This is the tricky part, bullshit 

   // show_linked_list (a[hash]);

   // write_hash_table(a);
   // read_hash_table();

}

inline  void example_loading_hash_table(){
    hash_table a = read_hash_table();
    
}




/*
 * This example, I show how to create an animal, writing in disk and 
 * Finally read that Animal in disk. 
 */
inline  void example_write_show_animal(){
    //animal a1;
    string name = "Tris"; 
    string type  = "Perro"; 
    string breed = "Criollo";
    char genre = 'F';    
    int32_t age = 30;       
    int32_t height = 5;    
    int32_t weight = 25;    
    
    animal a1(name, type, age, breed, height, weight, genre);  
    
    /* cout << "string: " << sizeof (string) << endl;
    cout << "Animal size: " << sizeof(animal) << endl;*/
    
    persist_register(a1);


   name = "Motas"; 
   type  = "Canario"; 
   breed = "Pura";
   genre = 'M';    
   age = 2;       
   height = 5;    
   weight = 25;    
    
    animal a2(name, type, age, breed, height, weight, genre);  
    

    persist_register(a2);

   // write_animal(a1,pos);
    read_animal(1);
      read_animal(2);
  //  show(a1);
}


