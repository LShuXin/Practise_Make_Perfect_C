#include <stdio.h>
#include <string.h>
#include "file_operation.h"

void write_string_to_file_then_read(char* path) {
    FILE *fp;
    char str[100];
    int i = 0;

    // 写文件
    if ((fp = fopen(path,"w")) == NULL) {
        printf("文件无法打开\n");
        return;
    }

    printf("请输入一个英文字符串:\n");
    gets(str);

    while (str[i] != '!') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }

        fputc(str[i], fp);
        i++;
    }
    fclose(fp);

    // 读文件
    fp = fopen(path,"r");
    fgets(str, strlen(str) + 1, fp);
    printf("从文件读出您输入的英文字母为：%s\n", str) ;
    fclose(fp);
}









void read_from_files_then_sort_and_write() {
    FILE *fp;
    int i, j, n;
    char c[100], ch;

    char* file_a_path = "/Users/apple/Desktop/a.txt";
    // char* file_a_path = "d:\\a.txt";
    // echo abcdefg > a.txt

    char* file_b_path = "/Users/apple/Desktop/b.txt";
    // char* file_b_path = "d:\\b.txt";
    // echo hijklmn > b.txt

    char* file_c_path = "/Users/apple/Desktop/c.txt";
    // char* file_c_path = "d:\\c.txt";
    //


    if ((fp = fopen(file_a_path, "r")) == NULL) {
        printf("can not open file:%s!\n", file_a_path);
        return;
    }
    printf("FILE:%s\n", file_a_path);
    for (i = 0; (ch = fgetc(fp)) != EOF; i++) {
        c[i] = ch;
        printf("%c", ch);
    }
    fclose(fp);


    if ((fp = fopen(file_b_path, "r")) == NULL) {
        printf("can not open file:%s!\n", file_b_path);
        return;
    }
    printf("FILE:%s\n", file_b_path);
    for (;(ch = fgetc(fp)) != EOF; i++) {
        c[i] = ch;
        printf("%c", ch);
    }
    fclose(fp);
    n = i;


    if ((fp = fopen(file_c_path, "w")) == NULL) {
        printf("can open file:%s！\n", file_c_path);
        return;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (c[i] > c[j]) {
                ch = c[i];
                c[i] = c[j];
                c[j] = ch;
            }
        }
    }

    for(i = 0; i < n; i++) {
        // 文件写入
        putc(c[i], fp);
        // 打印
        putchar(c[i]);
    }
    fclose(fp);
}










struct score_read_write_student
{
    int num;
    char name[20];
    float score[3];
    float ave;
};
void score_read_write() {
    int i , j;
    float sum;
    FILE *fp;

    struct score_read_write_student student_arr_1[5], student_arr_2[5];

    for (i = 0; i < 5; i++)
    {
        printf("*******请输入第%d个学生的数据*******\n", i + 1);
        printf("NO.:");
        scanf("%d", &student_arr_1[i].num);
        printf("姓名:");
        scanf("%s", &student_arr_1[i].name);
        sum = 0.0;
        for(j = 0; j < 3; j++)
        {
            printf("成绩%d:", j + 1);
            scanf("%f", &student_arr_1[i].score[j]);
            sum += student_arr_1[i].score[j];
        }
        student_arr_1[i].ave = sum / 3.0;
    }


    char* save_path = "/Users/apple/Desktop/student.txt";
    // char* save_path = "d:\\student.txt"
    if ((fp = fopen(save_path,"w")) == NULL)
    {
        printf("不能打开磁盘文件:%s\n", save_path);
        return;
    }
    for (i = 0; i < 5; i++) {
        if (fwrite(&student_arr_1[i], sizeof(struct score_read_write_student), 1, fp) != 1) {
            printf("文件写失败！\n");
            return;
        }
    }
    fclose(fp);


    if ((fopen(save_path,"r")) == NULL) {
        printf("文件读失败！\n");
        return;
    }
    for(i = 0; i < 5; i++) {
        fread(&student_arr_2[i], sizeof(struct score_read_write_student),1,fp);
        printf("NO.:%d  姓名:%s  成绩1:%f  成绩2:%f  成绩3:%f  平均成绩:%f\n", student_arr_2[i].num, student_arr_2[i].name,
               student_arr_2[i].score[0], student_arr_2[i].score[1], student_arr_2[i].score[2], student_arr_2[i].ave);
    }
    fclose(fp);
}