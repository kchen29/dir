#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
  printf("Statistics for directory: .\n");

  DIR *d = opendir(".");
  //go through directory once to print directory files
  printf("Directories:\n");
  struct dirent *entry = readdir(d);
  while (entry) {
    //. and .. are type unknown on the school computer
    if (entry->d_type != DT_REG)
      printf("\t%s\n", entry->d_name);
    entry = readdir(d);
  }
  closedir(d);

  d = opendir(".");
  //go through again to print regular files
  printf("Regular files:\n");
  long size = 0;
  entry = readdir(d);
  while (entry) { 
    if (entry->d_type == DT_REG) {
      struct stat sb;
      stat(entry->d_name, &sb);
      size += sb.st_size;
    }
    if (entry->d_type == DT_REG)
      printf("\t%s\n", entry->d_name);
    entry = readdir(d);
  }
  printf("Total size of regular files:\n\t%ld Bytes\n", size);
  closedir(d);
  return 0;
}
