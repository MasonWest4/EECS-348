#include <stdio.h>

void figure_score(int score){
int td, fg, sfty, td_2p, td_fg;

printf("Possible combinations of score %d :",score);
for (td_2p = 0; td_2p*8 <= score; td_2p++){
    for (td_fg = 0; td_fg*7 + td_2p*8 <= score; td_fg++){
        for (td = 0; td*6 + td_fg*7 + td_2p*8 <= score; td++){
            for (fg = 0; fg*3 + td*6 + td_fg*7 + td_2p*8 <= score; fg++){
                for (sfty = 0; sfty*2 + fg*3 + td*6 + td_fg*7 + td_2p*8 <= score; sfty++){
                    if (td_2p * 8 + td_fg * 7 + td * 6 + fg * 3 + sfty * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2p, td_fg, td, fg, sfty);
                    }
                }
            }
        }
    }
}
}

int main(){
    int score;
    while(1){
    printf("Enter score 0 or 1 to STOP\n");         
    printf("Enter the NFL Score: ");
    scanf("%d",&score);
    if (score <= 1){
        break;
        }
    figure_score(score);
    }
    return 0;
}