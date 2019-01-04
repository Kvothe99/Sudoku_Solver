
/* My header files */
#include<Sudoku.hpp>

/* STL header files */
#include<iostream>
#include<sys/mman.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/types>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char **argv)
{
  if(argc != 3)
  {
    std::cout << "Inproper command line inputs. Should be ./main [number] [file]." << std::endl;
    return false;
  }
  //connect to shared memory file
  shm_unlink(argv[2]);
  int shmID = shm_open(argv[2], O_RDWR | O_CREAT, 0666);
  if(-1 == shmID)
  {
    std::cout << "Failed to open " << *argv[2] << " as shared memory.\n" << 
                 strerror(errno) << std::endl;
    return false;
  }
  if(-1 == ftruncate(shmID, sizeof(Sudoku_obj)))
  {
    std::cout << "Failed to truncate " << *argv[2] << ".\n" << strerror(errno) << std::endl;
    return false;
  }
  void *shmPtr = mmap(NULL, sizeof(Sudoku_obj), PROT_WRITE, MAP_SHARED, shmID, 0);
  if(MAP_FAILED == shmPtr)
  {
    std::cout << "Failed to map " << *argv[2] << ".\n" << strerror(errno) << std::endl;
    return false;
  }
  //make sudoku to me given
  Sudoku_obj *SObjPtr = new(Sudoku_obj);

}
