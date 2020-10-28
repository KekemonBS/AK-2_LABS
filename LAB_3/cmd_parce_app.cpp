#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include <map>
#include <string>


int main(int argc, char **argv) {
    int res = 0;
	int index = -1;
    
    std::map <char, bool> call;
	
	const struct option lng[] = {
        {"help", 0, 0, 'h'},
        {"list", 0, 0, 'l'},
        {"version", 0, 0, 'v'},
        {"all", 0, 0, 'a'},
        {"display", 1, 0, 'd'},
        {0, 0, 0, 0},
    };

    while ((res = getopt_long(argc, argv, "hlvad:", lng, &index)) != -1){
		switch (res){
        case 'a': {
            if (call['a'] == false) {
                printf("Options\n"
                       "-h\t--help\tHelp\n"
                       "-l\t--list\tList\n"
                       "-v\t--version\tVersion\n"
                       "-d\t--display\tDisplay additional argument"
                       "-a\t--all\tThis message"); 				
                call['a'] = true;
				break;
			}
			break;
        }
		case 'h': {
			if (call['h'] == false) {
				printf("Arg: Help\n");
				call['h'] = true;
				break;
			} 
			break;
		}
		case 'l': {
			if (call['l'] == false) {
				printf("Arg: List\n");
				call['l'] = true;
				break;
			}
			break;
		}
		case 'v': {
			if (call['v'] == false) {
				printf("Arg: Version\n"); 
				call['v'] = true;
				break;
			}
			break;
		}
        case 'd': {
            if (call['d'] == false) {
                printf("Displaying optional value : %s\n", optarg); 				
                call['d'] = true;
				break;
			}
			break;
        }
		case '?': default: {
			printf("Argument %c does not exist\n", res);
			break;
			}
        }
		index = -1;
	}
}
