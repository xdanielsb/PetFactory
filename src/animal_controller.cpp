#include "file_animal.cpp"

/*
 * Refers to read animal from disk
 */
inline animal read_animal(int pos){
    animal a = read_file(pos);

    //Open the file
    //string cadena = "echo  \"The animal that was readen from disk was: \n Name: "+to_string(a)+ " \" > hist.clinic "; 

    //system(cadena.c_str());
    //system("gedit hist.clinic");
    show_animal(a);
    return a;
}
/*
 * Write animla in disk
 */
inline int write_animal(animal a){
    int pos = get_code();//Get the position in disk to storage the animal
    write_file(a, pos);   
  // read_animal(pos);
  return pos;
}


/*
 * Operation for the user for create an animal from memory to disk
 */
inline void insert_animal(){

    
    //Define the necesary fields for inserting an animal
    char name[32];   
    char type[32];   
    char breed[16];  
    char genre;    
    int32_t age;   
    int32_t height;
    int32_t weight;


    cout << "\n INSERT REGISTER \n";
    cout << " User we are going to ask you for some data, please ingress the data : "<<endl;


    cout << "\n\tName   = "; cin >> name;
    cout << "\n\ttype   = "; cin >> type;
    cout << "\n\tbreed  = "; cin >> breed;
    cout << "\n Genre if it is Female write a {F} but if it is Male  write  a {M}\n"; 
    cout << "\n\tgenre  = "; cin >> genre;
    cout << "\n\tage    = "; cin >> age;
    cout << "\n\theight = "; cin >> height;
    cout << "\n\tweight = "; cin >> weight;

    //Instance the animal
    animal a1(name, type, age, breed,height, weight, genre);   

    //Getting the hash number of the animal
    ll hash = get_hash(a1.name);
        
    //Persisting the animal and getting the location in disk
    ll location_disk = write_animal(a1);

    //Save location in hash table
    data[hash].push_back(location_disk);
    cout << "The register has been inserted succesfully" << endl;

}

/*
 * User operation for show the animal
 */

inline void show_animal(){
    ll total = 0;
    int number_register;
    cout << "\n SHOW REGISTER \n";
    for(int i=0; i< size_hash_table; i++){
        total += data[i].size();
    }
    cout << " Total number of registers is: " << total;
    cout << " User write the number of the register to see, please" << endl;
    cout << " Number of the register = " ;
    
    cin >> number_register;

    if (exist(number_register)){        //First Check in RAM
        read_animal(number_register);   //SECOND ACCESS TO DISK
    }else{
        cout << "\nUser that number is not register in the database\n";
    }

    
}
    

/*
 * Delete animal
 */
inline void delete_animal(){

    show_hash_table();
    int number_register;
    cout << "\n DELETE REGISTER \n";
    
    
    cout << " Number of the register = " ;
    
    cin >> number_register;

    if (exist(number_register)){      //Exist?  
        delete_item(number_register); //First delete from memory
    }else{
        cout << "\nUser that number is not registered in the database\n";
    }
    show_hash_table();

}

/*
 * Show animals with an specific name
 */
inline void show_animal_r(){
    string name;
    cout << "\n SHOW ANIMALS BY NAME\n";
    
    
    cout << " Name of the register = " ;

    cin >> name;
    int hash = get_hash (name);
    cout << endl <<"Names with the same hash" << endl;
    show_row_table(hash);
}

