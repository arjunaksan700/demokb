#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "dakon.h"

int main() {
	board b;
	int in;

	dakon_init(&b);

	printf("Siapa yang main dulu (0=PLYR1, 1=PLYR2) ? ");
	scanf("%d", &in);
	b.giliran = in;

	dakon_print(b);

	while(dakon_is_playable(b)) {
		int decision;
		printf("-- Giliran %s\n", dakon_get_player_name(b.giliran));

	 	if(b.giliran == DAKON_PLAYER_PLYR1) {
			do {
				srand((int)time(0));
				decision = (rand() % DAKON_LUBANG);
				
		
		//scanf("%d", &in);
				
			} while(b.lubang[b.giliran][decision] == 0);
			printf("Pilih lubang 1-%d: %d\n", DAKON_LUBANG, decision+1);
		} else {
			decision = abprune(b, 10, true);
			printf("Pilih lubang 1-%d: %d\n", DAKON_LUBANG, decision+1);
		}

		dakon_play(&b, decision, b.giliran);
		dakon_print(b);
		system("pause");
	}

	int diff = dakon_diff(b, DAKON_PLAYER_PLYR1);

	if(diff > 0) {
		printf("%s menang!\n", DAKON_PLAYER_PLYR1_NAME);
	} else if(diff < 0) {
		printf("%s menang!\n", DAKON_PLAYER_PLYR2_NAME);
	} else {
		printf("Seri!\n");
	}

	return 0;
}
