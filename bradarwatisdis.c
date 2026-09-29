#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "bradarwatisdisKIND.h"






int main(int argc,char *argv[]) {
	//if no file/dir entered helper
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}
	//multi-word filenames
	char filename[1024] = "";
	//also multi-word filenames
	for (int i = 1; i < argc; i++) {
		if (i > 1)
			strcat(filename, " ");

		strcat(filename, argv[i]);
	}


	struct stat st;
	//error handling
	if(stat(filename, &st) != 0) {
		fprintf(stderr, "pak you %s\n",filename);
		return 1;
	}
	//print file type
	printf("Content:  %s\n", kind(filename));
    //clear
	fflush(stdout);


	//Format & execution
	execlp("stat", "stat","--printf",
		   "File:     %n\n"
		   "Type:     %F\n"
		   "Size:     %s bytes\n"
		   "Perms:    %A (%a)\n"
		   "Owner:    %U:%G\n"
		   "Modified: %y\n",
		"--", filename, (char *)NULL);







	//returns 0
	return 0;
}
