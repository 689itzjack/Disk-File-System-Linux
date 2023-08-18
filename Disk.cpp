//Usuary: itzjackca
//Student name: Ytzjak Ariel Armoni i.d 336394010

#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

#define DISK_SIZE 256

// ============================================================================
void decToBinary(int n, char &c)
{
    // array to store binary number
    int binaryNum[8];
    // counter for binary array
    int i = 0;
    while (n > 0)
    {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        if (binaryNum[j] == 1)
            c = c | 1u << j;
    }
}
// ============================================================================

class FsFile {
    int file_size;
    int block_in_use;
    int index_block;
    int block_size;
    int max_capacity;

public:
    FsFile(int _block_size) {
        this->file_size = 0;//size file in chars
        this->block_in_use = 0;//number of the block in use
        this->block_size = _block_size;
        this->index_block = -1;//contains the number of the block that contains the block of the file
        this->max_capacity = block_size*block_size;
    }

    int getfile_size(){//return the current file size.
        return this->file_size;
    }
    int getblock_in_use(){//return how many blocks are in use.
        return this->block_in_use;
    }
    int get_index_block(){//return the index block from the file
        return this->index_block;
    }
    void up_file_size(int no_bytes){//increase the file size
        this->file_size+=no_bytes;
    }
    void down_file_size(int no_bytes){//decrease the file size
        this->file_size-=no_bytes;
    }
    void set_index_block(int no_block){//change the index block from -1 to its value
        this->index_block=no_block;
    }
    void up_block_in_use(){//increase number of blocks in use
        this->block_in_use+=1;
    }
    void down_block_in_use(){//decrease number of blocks in use
        this->file_size-=1;
    }
    int get_max_capacity_file(){//return the file max capacity
        return this->max_capacity;
    }
};

// ============================================================================

class FileDescriptor {
    string file_name;
    FsFile* fs_file;
    bool inUse;

public:

    FileDescriptor(string FileName, FsFile* fsi) {
        file_name = FileName;
        fs_file = fsi;
        inUse = true;
    }

    string getFileName() {//RETURN THE FILE NAME
        return file_name;
    }
    bool get_in_use(){//RETURN IF THE FILE IS IN USE
        return inUse;
    }
    void set_in_use(){//CHANGE THE STATUS IN USE TO BE TRUE
        inUse= true;
    }
    void set_not_in_use(){//CHANGE THE STATUS IN USE TO BE FALSE
        inUse= false;
    }
    FsFile* get_fs_file(){//RETURN THE INFORMATION FILE
        return fs_file;
    }
    void closing_File(){//HELPS TO CLOSE A FILE
        file_name = "";
        fs_file = NULL;
        inUse = false;
    }

};
//////////////////////////////////////////////FUNCTIONS PRINTERS CLASS fsDisk///////////////////////////////////////////
void print_Bit_Vector(int *bitVec, int size_bitVec){// prints the BitVector
    int i=0;
    for(i ; i < size_bitVec ; i++){
        printf("index: %d, value: %d \n", i , bitVec[i]);
    }
}
void print_FsFile(FsFile* cur_file){//the method prints the contains of the Fsfile of the file
    cout<<"The file size is: "<<cur_file->getfile_size()<<"\nThe block is use is: "<<cur_file->getblock_in_use()
    <<"\nThe index block is: "<<cur_file->get_index_block()<<"\nThe max size file: "<<cur_file->get_max_capacity_file()<<endl<<endl<<endl;
}
void print_Vector(vector<FileDescriptor> vec){//the method prints what a vector contains
    for(FileDescriptor item: vec){
        if(item.getFileName() == ""){
            printf("EXIST BLANK SPACE \n\n");//==================================================
            continue;
        }
        cout<<"NAME FILE: "<<item.getFileName()<<endl<<"DATA: "<<endl;
        print_FsFile(item.get_fs_file());
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------
////////////////////////////////CLASS METHODS FSDISK////////////////////////////////////////////////
int seek_free_block_in_BitVector(int* Bit_Vec, int size_Bit_Vec){//the method gets the BitVector and looks for a free block
    //returns the free block if it exists, otherwise -1
    int i;
    for(i=0 ; i < size_Bit_Vec; i++){
        if(Bit_Vec[i] == 0)
            return i;
    }
    return -1;
}
bool search_a_file_in_Vector(vector<FileDescriptor> files , string found_file){//the method get a FD vector
    //and a name file to search it at the vector.Returns true if the file is in the vector, otherwise false.
    for(FileDescriptor item : files){
        if(item.getFileName() == found_file)
            return true;
    }
    return false;
}
int fd_File(vector<FileDescriptor> files , string found_file){//the method get a FD vector and a name file
    //to search it at the vector.Returns the fd if the file is in the vector, otherwise -1.
   int fd = 0;
    for(FileDescriptor item : files){
        if(item.getFileName() == found_file)
            return fd;
        fd++;
    }
    return -1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define DISK_SIM_FILE "DISK_SIM_FILE.txt"

// ========================================CLASS FSDISK====================================

class fsDisk {
    FILE *sim_disk_fd;
    bool is_formated;
    int blockSIZE = 0;
    int BitVectorSize;
    int *BitVector;
    vector<FileDescriptor> MainDir;
    vector<FileDescriptor> OpenFileDescriptors;//CONTAINS ALL THE FILES FROM THE DIRECTORY


    // ------------------------------------------------------------------------
public:
    fsDisk() {
        sim_disk_fd = fopen(DISK_SIM_FILE , "r+");
        if(sim_disk_fd == NULL) {
            perror("The file DISK_SIM_FILE.txt doesn't exist\n");
            exit(EXIT_FAILURE);
        }
        assert(sim_disk_fd);

        for (int i=0; i < DISK_SIZE ; i++) {
            int ret_val = fseek ( sim_disk_fd , i , SEEK_SET );
            ret_val = fwrite( "\0" ,  1 , 1, sim_disk_fd);
            assert(ret_val == 1);
        }

        fflush(sim_disk_fd);
        is_formated = false;
    }

    ~fsDisk(){
        fclose(sim_disk_fd);//closing the file Disk.
        delete [] BitVector;// deleting and freeing allocated memory of BitVector.
        BitVector=NULL;
        for(FileDescriptor item : MainDir){
            delete item.get_fs_file();
        }
    }

    // ------------------------------------------------------------------------
    void listAll() {//PRINTS THE DISK CONTAIN
        int i = 0;
        for (FileDescriptor item : MainDir) {
            cout << "index: " << i << ": FileName: " << item.getFileName() <<  " , isInUse: " <<item.get_in_use() << endl;
            i++;
        }

        char bufy;
        cout << "Disk content: '"<<endl;
        for (i = 0; i < DISK_SIZE; i++)
        {
            cout << "(";
            int ret_val = fseek(sim_disk_fd, i, SEEK_SET);
            ret_val = fread(&bufy, 1, 1, sim_disk_fd);
            cout << bufy;
            cout << ")";
            //if( i % 36 == 0 && i != 0)
               // cout<<endl;
        }
        cout << "'" << endl;
    }

    // ------------------------------------------------------------------------
    void fsFormat( int blockSize =4 ) {//GETS THE BLOCK SIZE AND FORMATS THE DISK

        if(is_formated == true){
            printf("The disk was already formatted\n");
            return;
        }
        blockSIZE = blockSize;
        is_formated = true;
        BitVectorSize = DISK_SIZE/blockSize;
        cout<<"FORMAT DISK: number of blocks: "<<BitVectorSize<<endl;
        BitVector = new int[BitVectorSize];
        memset(BitVector,0,BitVectorSize);//starting BitVector with the value 0.
    }

    // ------------------------------------------------------------------------
    int CreateFile(string fileName) {//GETS A STRING AND CREATES A NEW FILE IN THE DISK
        int free_block;
        char No_block='0' ;
        FsFile* new_struct_file;
        bool file_exist = false;

        if(is_formated == false){
            fprintf(stderr,"Error: we cannot create the file because the Disk has not been formmated yet\n");
            cout<<"Please format the Disk pressing the number: 2 and the number size block that you need.\n";
            return -1;
        }

        free_block = seek_free_block_in_BitVector(BitVector,BitVectorSize);
        if(free_block == -1){
            fprintf(stderr,"The Disk is full, please delete files\n");
            return -1;
        }

        if(search_a_file_in_Vector(MainDir , fileName) == true){
            fprintf(stderr , "The file already exist, try another name\n");
            return -1;
        }

        new_struct_file = new FsFile(blockSIZE);
        new_struct_file->set_index_block(free_block);
        BitVector[free_block] = 1;
        FileDescriptor new_file(fileName,new_struct_file);
        new_file.set_in_use();
        MainDir.push_back(new_file);

        int free_in = looking_free_FD();//CONTAINS A FILE DESCRIPTOR OF A DELETED FILE.
        if(free_in < 0){
            OpenFileDescriptors.push_back(new_file);
            //cout<<"THE VECTOR FILE DESCRIPTORS HAS:\n\n";//==========================================
            //print_Vector(OpenFileDescriptors);//==============================================
            return OpenFileDescriptors.size()-1;
        }
        OpenFileDescriptors.erase(OpenFileDescriptors.begin() + free_in);
        OpenFileDescriptors.insert(OpenFileDescriptors.begin() + free_in ,new_file);
        //print_Vector(OpenFileDescriptors);//==============================================
        return free_in;
    }

    // ------------------------------------------------------------------------
    int looking_free_FD(){//return a cell empty in the FD table if exist, otherwise -1
        int fd_founded = 0;
        for(FileDescriptor item : OpenFileDescriptors){
            if(item.getFileName() == "")
                return fd_founded;
            fd_founded++;
        }
        return -1;
    }
    int OpenFile(string fileName) {//GETS A FILE NAME AND OPEN IT IF IT CLOSED BEFORE

        if(is_formated == false){//checking if the DISK is formatted already
            fprintf(stderr,"Error: we cannot open the file because the Disk has not been formatted yet\n");
            cout<<"Please format the Disk pressing the number: 2 and the number size block that you need.\n";
            return -1;
        }

        bool is_open = search_a_file_in_Vector(OpenFileDescriptors , fileName);// the variable show us if the file is open or not yet.
        if(is_open == true){//IF THE FILE IS OPEN, WE SHOW THE FD FILE.
            int index_fd = fd_File(OpenFileDescriptors,fileName);
            cout<<"The file is already open"<<endl<<"The fd file is: "<<index_fd<<endl;
            return -1;
        }
        //////////////IF THE FILE IS CLOSE

        bool exist = search_a_file_in_Vector(MainDir,fileName);
        if(exist == false){//if the required file doesn't exist.
            fprintf(stderr, "The file has not been created.\n");
            return -1;
        }
        int file_des = fd_File(MainDir,fileName);
        MainDir.at(file_des).set_in_use();

        int free_in = looking_free_FD();
        if(free_in < 0){
            OpenFileDescriptors.push_back(MainDir.at(file_des));
            //print_Vector(OpenFileDescriptors);//==============================================
            return OpenFileDescriptors.size()-1;
        }
        OpenFileDescriptors.erase(OpenFileDescriptors.begin() + free_in);
        OpenFileDescriptors.insert(OpenFileDescriptors.begin() + free_in ,MainDir.at(file_des));
        //print_Vector(OpenFileDescriptors);//==============================================
        return free_in;
    }

    // ------------------------------------------------------------------------

    string CloseFile(int fd) {//GETS A FD TO BE CLOSED
        if(is_formated == false){//checking if the DISK is formmated
            fprintf(stderr,"Error: we cannot close the file because the Disk has not been formatted yet\n");
            cout<<"Please format the Disk pressing the number: 2 and the number size block that you need.\n";
            return "-1";
        }
        if(fd > OpenFileDescriptors.size()-1 || fd < 0){//checking if the fd is valid
            fprintf(stderr, "Error: The file descriptor is not valid.\n");
            return "-1";
        }
        if(OpenFileDescriptors.at(fd).getFileName() == ""){
            fprintf(stderr, "Error: File Descriptor not available, The file has been closed already.\n");
            return "-1";
        }
        if(OpenFileDescriptors.size() == 0){
            fprintf(stderr, "Error: Close Failed, There are not open files.\n");
            return "-1";
        }
        int ind_in_MD;
        string file_closed=OpenFileDescriptors.at(fd).getFileName();
        ind_in_MD = fd_File(MainDir, file_closed);
        MainDir.at(ind_in_MD).set_not_in_use();
        //cout<< "BEFORE TO CLOSE THE FILE!!!!!!!!!!!"<<file_closed<<endl;//=============================================
        //print_Vector(OpenFileDescriptors);//==============================================
        //OpenFileDescriptors.erase(OpenFileDescriptors.begin()+fd);//EDITING.....................................................
        OpenFileDescriptors.at(fd).closing_File();
        //cout<<"WHEN THE FILE IS ALREADY CLOSED=======================================-------------------------"<<endl;//====================
        //print_Vector(OpenFileDescriptors);//==============================================
        //cout<<"ALL THE FILES DIRECTORY ARE: [[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]"<<endl;//==================
        //print_Vector(MainDir);//=============================================
        return file_closed;
    }

    // ------------------------------------------------------------------------

    int writing_Execution(int num_of_block, string data){//GETS THE NUMBER BLOCK WHERE THE DATA WILL BE WRITTEN.
        int bytes_written=0;
        num_of_block *= blockSIZE;
        char letter[1];
        int ret_val = fseek(sim_disk_fd, num_of_block, SEEK_SET);

        if(ret_val != 0){
            perror("Error: function fseek() failed in func writing_to_DISK\n");
            return -1;
        }
        int idx=0;
        while( idx < blockSIZE){
            if(data[idx] == '\0')
                break;
            //letter[0]=data[idx];
            fwrite(&data[idx],1,1,sim_disk_fd);
            bytes_written++;
            idx++;
        }
        return bytes_written;
    }

    int fill_block_to_complete(int number_block, string data){//gets the string to save it in the block to fill
        // data to be written.
        int seek_valid;
        int logical_address = number_block * blockSIZE;
        int ret_val;
        char letter;
        int written = 0;
        int index = 0;

        seek_valid = fseek(sim_disk_fd, logical_address, SEEK_SET);
        if(seek_valid != 0){
            perror("Error: function fseek() failed in func writing_to_DISK\n");
            return -1;
        }
        while(1){
            ret_val = fread(&letter, 1, 1, sim_disk_fd);
            if(ret_val < 0){
                perror("Error: function fread() failed in func writing_to_DISK\n");
                return -1;
            }
            if(index == blockSIZE || data[written] == '\0')
                break;
            if(letter == '\0'){
                seek_valid = fseek(sim_disk_fd, -1, SEEK_CUR);
                if(seek_valid != 0){
                    perror("Error: function fseek() failed in method fill_block_to_complete\n");
                    return -1;
                }
                if(fwrite(&data[written],1,1,sim_disk_fd) ==0){
                    perror("Error: function fwrite failed in method fill_block_to_complete\n");
                    return -1;
                }
                written++;
            }
            index++;
        }
        return written;
    }

    int writing_to_DISK(int fd, int logical_address , char* data, int num_chars_2_write){//GETS THE BLOCK INDEX
        //BLOCK,THE DATA TO SAVE AND HOW MANY DATA WE WILL WRITE AND SAVE IT IN THE DISK.
        int free_block;
        int  i;
        char bufy2;
        char num_block_Binary='\0';
        string data_to_write(data);
        int chars_written=0;
        int write_in_block;
        int total_chars_written = 0;
        int ret_val;
        int seek_valid;
        int offset_logical = OpenFileDescriptors.at(fd).get_fs_file()->getblock_in_use();//up the blocks in use.;
        bool needs_fill = true;

        if((OpenFileDescriptors.at(fd).get_fs_file()->getfile_size() % blockSIZE) == 0)
            needs_fill = false;


        for (i = 0; i < blockSIZE; i++){//THE LOOP OVER ON THE INDEX BLOCK DATA AND GETS THE NUMBER BLOCKS.
            if(total_chars_written == num_chars_2_write)
                break;

            if(needs_fill == true){

                seek_valid = fseek(sim_disk_fd, logical_address + offset_logical-1, SEEK_SET);
                if(seek_valid != 0){
                    perror("Error: function fseek() failed in func writing_to_DISK\n");
                    return -1;
                }
                ret_val = fread(&bufy2, 1, 1, sim_disk_fd);
                if(ret_val < 0){
                    perror("Error: function fread() failed in func writing_to_DISK\n");
                    return -1;
                }
                int num_block_in_Dec = bufy2 - 48;
                chars_written = fill_block_to_complete(num_block_in_Dec, data_to_write);
                total_chars_written += chars_written;
                data_to_write = data_to_write.substr(chars_written);
                chars_written = 0;
                num_block_Binary = '\0';
                needs_fill = false;
            }

            else{
                seek_valid = fseek(sim_disk_fd, logical_address + offset_logical, SEEK_SET);
                if(seek_valid != 0){
                    perror("Error: function fseek() failed in func writing_to_DISK\n");
                    return -1;
                }
                free_block = seek_free_block_in_BitVector(BitVector,BitVectorSize);
                if(free_block == -1){
                    fprintf(stderr,"The Disk is full, please delete files\n");
                    return total_chars_written;
                }
                BitVector[free_block] = 1;//THE FOUNDED PLACE IS NOW OCCUPIED.
                decToBinary(free_block+48,num_block_Binary);
                //printf("THE NUMBER BLOCK IS THE CHAR: %c, AND THE INT VAL IS: %d\n",num_block_Binary, num_block_Binary);//=====================
                fwrite(&num_block_Binary,1,1,sim_disk_fd);
                OpenFileDescriptors.at(fd).get_fs_file()->up_block_in_use();//up the blocks in use.
                chars_written += writing_Execution(free_block,data_to_write);
                total_chars_written += chars_written;
                data_to_write = data_to_write.substr(chars_written);
                chars_written = 0;
                num_block_Binary = '\0';
                offset_logical = OpenFileDescriptors.at(fd).get_fs_file()->getblock_in_use();//up the blocks in use.

            }
        }
        return total_chars_written;
    }

    int WriteToFile(int fd, char *buf, int len ) {
        int written_chars;

        if(is_formated == false){
            fprintf(stderr,"Error: we cannot write to the file because the Disk has not been formmated yet\n");
            cout<<"Please format the Disk pressing the number: 2 and the number size block that you need.\n";
            return -1;
        }

        if(fd > OpenFileDescriptors.size()-1 || fd < 0){//checking if the fd is valid
            fprintf(stderr, "Error: The file descriptor is not valid.\n");
            return -1;
        }

        if(OpenFileDescriptors.at(fd).getFileName() == ""){
            fprintf(stderr, "Error: File Descriptor not available, The file to write has been closed.\n");
            return -1;
        }

        FileDescriptor write_on_file=OpenFileDescriptors.at(fd);
        int curr_file_size = write_on_file.get_fs_file()->getfile_size();
        int max_file_size = write_on_file.get_fs_file()->get_max_capacity_file();
        int free_space_in_file = max_file_size - curr_file_size;

        if(curr_file_size == max_file_size){//we check if the file is already full.
            fprintf(stderr, "Error: You reach the max file capacity, PLease delete data\n");
            return -1;
        }

        else if(free_space_in_file < len){//we check if we have enough space in the file, if not we write the
            // data we reach.
            fprintf(stderr, "WARNING! The space is not enough to write all the data.\n");
            fprintf(stderr,"Space enough just for: %d chars of data.\n",free_space_in_file);
            written_chars = free_space_in_file;
        }

        else written_chars = len;

        int index_block_file=OpenFileDescriptors.at(fd).get_fs_file()->get_index_block();
        int logical_address = index_block_file * blockSIZE;//location in DISK to write on.
        written_chars = writing_to_DISK(fd, logical_address, buf, written_chars);
        if(written_chars <= 0)
            return -1;
        OpenFileDescriptors.at(fd).get_fs_file()->up_file_size(written_chars);
        //print_Vector(OpenFileDescriptors);//===========================================
        //print_Vector(MainDir);//===========================================
        return written_chars;
    }

    // ------------------------------------------------------------------------

    int delete_Block(int num_Block){//GETS THE NUMBER BLOCK AND DELETES ALL ITS CONTAIN
        int seek_valid;
        int logical_address = num_Block * blockSIZE;
        int idx = 0;
        char char_del[1];
        char_del[0] = '\0';

        seek_valid = fseek(sim_disk_fd, logical_address, SEEK_SET);
        if(seek_valid != 0){
            perror("Error: function fseek() failed in func delete_Block()\n");
            return -1;
        }
        while(idx < blockSIZE){
            if (fwrite(char_del,1,1,sim_disk_fd) <= 0){
                perror("Error: the function fwrite() failed, in func delete_Block()\n");
                return -1;
            }
            idx++;
        }
        BitVector[num_Block] = 0;
        return 0;
    }

    int delete_Index_Block(int index_block){//GETS THE INDEX BLOCK FILE AND DELETE ALL THE POINTERS WITH THE
        // HELP OF THE FUNCTION delete_Block()
        int address_block;
        int seek_valid;
        int valid_read;
        char data_read;
        int idx_curr_block = 0;
        char chr_del[1];
        chr_del[0] = '\0';

        address_block = (index_block * blockSIZE) + idx_curr_block;
        seek_valid = fseek(sim_disk_fd, address_block, SEEK_SET);
        if(seek_valid != 0){
            perror("Error: function fseek() failed in func writing_to_DISK\n");
            return -1;
        }
        while(idx_curr_block < blockSIZE){
            valid_read = fread(&data_read, 1, 1, sim_disk_fd);
            if(valid_read < 0){
                perror("Error: function fread() failed in func writing_to_DISK\n");
                return -1;
            }
            if(data_read == '\0'){
                break;
            }
            data_read -=48;
            if(delete_Block((int)data_read) < 0)
                return -1;

            seek_valid = fseek(sim_disk_fd, address_block + idx_curr_block, SEEK_SET);
            if(seek_valid != 0){
                perror("Error: function fseek() failed in func writing_to_DISK\n");
                return -1;
            }
            if(fwrite(chr_del,1,1,sim_disk_fd) <= 0){
                perror("Error in function fwrite(), writing failed\n");
                return -1;
            }
            idx_curr_block++;

        }
        cout<<"Deleting Finished Successfully"<<endl;
        return 0;
    }

    int deleting_File_from_MainDir(vector<FileDescriptor> MD, string file_name){//GETS THE MAIN DIR AND THE
        // FILE NAME TO BE DELETED WITH THE HELP OF THE FUNCTION delete_Index_Block()
        int index=0;
        int idx_block;
        for(FileDescriptor item: MD){
            if(item.getFileName() == file_name){
                idx_block = item.get_fs_file()->get_index_block();
                if(delete_Index_Block(idx_block) < 0)
                    return -1;
                delete MainDir.at(index).get_fs_file();
                MainDir.erase(MainDir.begin() + index);
                BitVector[idx_block] = 0;
                break;
            }
            index++;
        }
        return 0;
    }

    int DelFile( string FileName ) {//GETS A FILE NAME AND DELETE IT FROM THE DIRECTORY

        if(is_formated == false){
            fprintf(stderr,"Error: we cannot delete the file because the Disk has not been formatted yet\n");
            cout<<"Please format the Disk pressing the number: 2 and the number size block that you need.\n";
            return -1;
        }
        bool the_file_exist;
        the_file_exist = search_a_file_in_Vector(MainDir,FileName);
        if(the_file_exist == false){
            fprintf(stderr, "The file not founded, Please check again the File name\n");
            return -1;
        }
        int file_is_open;
        int idx_MD;
        file_is_open = fd_File(OpenFileDescriptors, FileName);

        if(file_is_open >= 0){//CLOSING THE FILE FROM THE OPEN FILE DESCRIPTORS
            fprintf(stderr, "Error: The file is open, Please close it before delete it\n");
            return -1;
        }
        else{
            idx_MD = fd_File(MainDir,FileName);
            if(deleting_File_from_MainDir(MainDir,FileName) < 0)
                return -1;
        }
        //print_Vector(MainDir);//============================================
        return idx_MD;
    }

    // ------------------------------------------------------------------------
    string data_Read(int no_block, int size_to_read){//GET A BLOCK NUMBER AND THE SIZE TO BE READ AND
        // RETURNS THE DATA STRING OBTAINED
        int address_data = no_block * blockSIZE;
        int index_data = 0;
        string data_collected = "";
        int seek_valid;
        int valid_read;
        char chr_read;

        seek_valid = fseek(sim_disk_fd, address_data, SEEK_SET);
        if(seek_valid != 0){
            perror("Error: function fseek() failed in func data_Read()\n");
            return "-1";
        }

        while(index_data < blockSIZE){
            if(index_data == size_to_read)
                break;
            valid_read = fread(&chr_read, 1, 1, sim_disk_fd);
            if(valid_read < 0) {
                perror("Error: function fread() failed in func data_Read()\n");
                return "-1";
            }
            data_collected += chr_read;
            index_data++;
        }
        return data_collected;
    }

    string collecting_Data_from_File(int idx_block, int aim){//GETS THE INDEX BLOCK FILE TO COLLECT THE DATA REQUIRED
        int address_logical = idx_block * blockSIZE;
        int seek_valid;
        int valid_read;
        int block_number = 0;
        int counter = 0;
        char block;
        string piece_data_obtained = "";
        string res;

        while(block_number < blockSIZE){

            if(aim == 0)
                break;

            seek_valid = fseek(sim_disk_fd, address_logical + block_number, SEEK_SET);
            if(seek_valid != 0){
                perror("Error: function fseek() failed in func writing_to_DISK\n");
                return "-1";
            }
            valid_read = fread(&block, 1, 1, sim_disk_fd);
            if(valid_read < 0){
                perror("Error: function fread() failed in func writing_to_DISK\n");
                return "-1";
            }
            block -= 48;
            res = data_Read((int)block, aim);
            if(res == "-1")
                return "-1";
            piece_data_obtained += res;
            block_number++;
            aim -= res.size();
        }
        return piece_data_obtained;
    }

    int ReadFromFile(int fd, char *buf, int len ) {//GETS A FD AND THE SIZE TO BE READ, THE STRING READ IS
        // SAVED IN THE BUF PARAMETER

        if(is_formated == false){
            fprintf(stderr,"Error: we cannot read from the file because the Disk has not been formmated yet\n");
            cout<<"Please format the Disk pressing the number: 2 and the number size block that you need.\n";
            return -1;
        }

        if(fd > OpenFileDescriptors.size()-1 || fd < 0){//checking if the fd is valid
            fprintf(stderr, "Error: The file descriptor is not valid.\n");
            fprintf(stderr, "Please enter a file descriptor valid.\n");
            return -1;
        }

        if(OpenFileDescriptors.at(fd).getFileName() == ""){
            fprintf(stderr, "Error: File Descriptor not available, The file to read has been closed.\n");
            return -1;
        }

        string data_ret;
        int index_block = OpenFileDescriptors.at(fd).get_fs_file()->get_index_block();

        int size_curr_file = OpenFileDescriptors.at(fd).get_fs_file()->getfile_size();
        if(size_curr_file == 0){
            fprintf(stderr, "The file is empty, please put data on it.\n");
            return -1;
        }

        if(size_curr_file < len){
            fprintf(stderr, "The file doesn't contain the enough data that you want to read\n");
            fprintf(stderr, "The file just contain the next data:\n");
            //return -1;
        }

        data_ret = collecting_Data_from_File(index_block, len);
        if(data_ret == "-1")
            return -1;

        strcpy(buf, data_ret.c_str());
        return data_ret.size();
    }
};
//////////////////////////////////////////funct SOS MAIN

int main() {
    int blockSize;
    int direct_entries;
    string fileName;
    char str_to_write[DISK_SIZE];
    char str_to_read[DISK_SIZE];
    int size_to_read;
    int _fd;

    cout<<"Starting Program..."<<endl;
    fsDisk *fs = new fsDisk();
    cout<<"Disk started, please format the Disk.\n";
    int cmd_;
    while(1) {
        cin >> cmd_;
        switch (cmd_)
        {
            case 0:   // exit
                delete fs;
                exit(0);
                break;

            case 1:  // list-file
                fs->listAll();
                break;

            case 2:    // format
                cin >> blockSize;
                fs->fsFormat(blockSize);
                break;

            case 3:    // creat-file
                cin >> fileName;
                _fd = fs->CreateFile(fileName);
                if(_fd >= 0)
                    cout << "CreateFile: " << fileName << " with File Descriptor #: " << _fd << endl;
                break;

            case 4:  // open-file
                cin >> fileName;
                _fd = fs->OpenFile(fileName);
                if(_fd >= 0)
                    cout << "OpenFile: " << fileName << " with File Descriptor #: " << _fd << endl;
                break;

            case 5:  // close-file
                cin >> _fd;
                fileName = fs->CloseFile(_fd);
                if(fileName != "-1")
                    cout << "CloseFile: " << fileName << " with File Descriptor #: " << _fd << endl;
                break;

            case 6:   // write-file
                cin >> _fd;
                cin >> str_to_write;
                int num_chars;
                num_chars = fs->WriteToFile( _fd , str_to_write , strlen(str_to_write) );
                if(num_chars >= 0)
                    cout<<"Written "<<num_chars<<" Chars into file descriptor #: "<<_fd<<endl;
                break;

            case 7:    // read-file
                cin >> _fd;
                cin >> size_to_read ;
                if(fs->ReadFromFile( _fd , str_to_read , size_to_read ) > 0)
                    cout << "ReadFromFile: " << str_to_read << endl;
                break;

            case 8:   // delete file
                cin >> fileName;
                _fd = fs->DelFile(fileName);
                if(_fd >= 0)
                    cout << "DeletedFile: " << fileName << " with Index Main Directory #: " << _fd << endl;
                break;
            default:
                break;
        }
    }

}
/*void printing_valuesASCCI(){
    int free_block=0;
    char bin_block='\0';
    int no_block;
    for(no_block=0; no_block < 128; no_block++){
        decToBinary(no_block+48, bin_block);
        cout<<"THE NUMBER BLOCK IN DECIMAL IS: "<<no_block<<" THE NUMBER BLOCK IN BINARY: "<<bin_block<<endl;
        cout<<"THE NUMBER BLOCK IN BINARY: "<<bin_block<<" THE NUMBER BLOCK IN DECIMAL IS: "<<(int)bin_block-48<<endl<<endl;
        bin_block='\0';
    }
}*/
//printing_valuesASCCI();

/*fgets(str_to_write,DISK_SIZE,stdin);
cout<<"THE CHAR ARR: "<<str_to_write<<endl;
string converted(str_to_write);
cout<<"THE CHAR ARR CONVERTED IN STR: "<<converted<<endl;
cout<<"THE STRING CUT: "<<converted.substr(5)<<endl;
cout<<"THE STRING ORIG: "<<converted<<endl;
converted = converted.substr(5);
cout<<"THE STRING CUT UPDATED: "<<converted<<endl;*/