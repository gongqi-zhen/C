#include <stdio.h>

/* 管理するデータの上限個数 */
#define MAX_NUM (10)

/* キュー構造体 */
typedef struct QUEUE {
    /* データの最後尾 */
    int tail;
    /* キューされているデータ */
    int data[MAX_NUM];
} QUEUE_T;

void initQueue(QUEUE_T*);
void printQueue(QUEUE_T*);
void enqueue(QUEUE_T*, int);
int dequeue(QUEUE_T*);

/* キューを初期化する関数 */
void initQueue(QUEUE_T *queue){

    /* キューを空に設定 */
    queue->tail = -1;
}

/* ENQUEUEする関数 */
void enqueue(QUEUE_T *queue, int input){

    /* キューが満杯なら何もせず関数終了 */
    if(queue->tail == MAX_NUM - 1){
        printf("キューが満杯でENQUEUEできません\n");
        return;
    }

    /* データをデータの最後尾の１つ後ろに格納 */
    queue->data[queue->tail + 1] = input;

    /* データの最後尾を１つ後ろに移動 */
    queue->tail = queue->tail + 1;
}

/* DEQUEUEする関数 */
int dequeue(QUEUE_T *queue){
    int ret = 0;
    int i;

    /* キューが空なら何もせずに関数終了 */
    if(queue->tail == -1){
        printf("キューが空です\n");
        return -1;
    }

    /* データの先頭からデータを取得 */
    ret = queue->data[0];

    /* データの先頭より後ろのデータを１つずつ前にずらす */
    for (i = 0; i < queue->tail; i++) {
        queue->data[i] = queue->data[i + 1];
    }

    /* データの最後尾も１つ前にずらす */
    queue->tail = queue->tail - 1;

    /* 取得したデータを返却 */
    return ret;
}

/* キューの中身を表示 */
void printQueue(QUEUE_T *queue){
    int i = 0;
    
    printf("左側がキューの出口側を表しています\n");
    for(i = 0; i <= queue->tail; i++){
        printf("%d,", queue->data[i]);
    }
    printf("\n");
}

int main(void){

    int m;
    int input;
    int output;
    QUEUE_T queue;

    /* キューを初期化 */
    initQueue(&queue);

    while(1){
        /* ユーザからメニューを選んでもらう */
        printf("メニュー\n 1:ENQUEUE\n 2:DEQUEUE\n 3:キュー表示\n それ以外の数字:終了\n");
        scanf("%d", &m);

        /* 選ばれたメニューに応じて処理を分岐 */
        if(m == 1){
            printf("ENQUEUEする数は？（正の整数のみ化）");
            scanf("%d", &input);
            if (input < 0) {
                printf("負の値は受け付けていません!\n");
                continue;
            }
            printf("%dをENQUEUEします\n", input);
            enqueue(&queue, input);
        }else if(m == 2){
            printf("DEQUEUEします\n");
            output = dequeue(&queue);
            if(output != -1){
                printf("%dをDEQUEUEしました\n", output);
            }
        } else if(m == 3){
            printf("キューの中身を表示します\n");
            printQueue(&queue);
        } else {
            /* 1, 2, 3以外の場合はwhile文を抜け出すためにbreakを実行 */
            printf("終了します\n");
            break;
        }
    }
    return 0;
}