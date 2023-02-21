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









void read_score_sort_and_write() {
    int i, j;
    FILE *fp;
    struct score_read_write_student students[5], temp;

    char* read_path = "/Users/apple/Desktop/student.txt";
    char* save_path = "/Users/apple/Desktop/student_sorted.txt";


    // 显示原始数据
    if ((fp = fopen(read_path,"r")) == NULL)
    {
        printf("文件读失败!\n");
        return;
    }
    printf("原始数据为:\n");
    for (i = 0; fread(&students[i], sizeof(struct score_read_write_student),1, fp) != 0; i++)
    {
        printf("NO.:%-4d  姓名：%-6s  成绩1:%5.f  成绩2:%5.f  成绩3:%5.f  平均成绩:%5.f\n",
               students[i].num, students[i].name, students[i].score[0], students[i].score[1],
               students[i].score[2], students[i].ave);
    }
    fclose(fp);

    // 排序
    printf("排序之后的数据为:\n");
    for (i = 0; i < 5; i++)
    {
        for(j = i + 1; j < 5; j++)
        {
            if (students[j].ave > students[i].ave)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }

        }
        printf("NO.:%-4d  姓名：%-6s  成绩1:%5.f  成绩2:%5.f  成绩3:%5.f  平均成绩:%5.f\n",
               students[i].num, students[i].name, students[i].score[0], students[i].score[1],
               students[i].score[2], students[i].ave);

    }

    // 保存为新的文件
    if ((fp = fopen(save_path,"w")) == NULL)
    {
        printf("文件写失败\n");
        return;
    }
    for (i = 0; i < 5; i++)
    {
        if (fwrite(&students[i], sizeof(struct score_read_write_student), 1, fp) != 1)
        {
            printf("文件写失败！\n");
            return;
        }
    }
    printf("%s写入成功！", save_path);
    fclose(fp);
}







void write_record_to_sorted_file() {
    FILE *fp;
    int i, n;
    float sum;

    struct score_read_write_student students[5], temp;
    char* read_path = "/Users/apple/Desktop/student_sorted.txt";
    char* save_path = "/Users/apple/Desktop/student_sorted_insert.txt";

    // 从磁盘中读取并显示已有的数据
    if ((fp = fopen(read_path, "r")) == NULL)
    {
        printf("文件打开失败！\n");
        return;
    }
    for (i = 0; i < 5; i++)
    {
        if (fread(&students[i], sizeof(struct score_read_write_student), 1, fp) != 1)
        {
            printf("文件读取过程中出错！");
            return;
        }
        else
        {
            printf("NO.:%-4d  姓名：%-6s  成绩1:%5.f  成绩2:%5.f  成绩3:%5.f  平均成绩:%5.f\n",
                   students[i].num, students[i].name, students[i].score[0], students[i].score[1],
                   students[i].score[2], students[i].ave);
        }
    };
    fclose(fp);




    // 读入一组新的数据
    printf("请输入新的数据：\n");
    printf("NO.:");
    scanf("%d", &temp.num);
    printf("姓名：");
    scanf("%s", &temp.name);
    sum = 0.0;
    for (i = 0; i < 3; i++)
    {
        printf("成绩%d:", i + 1);
        scanf("%f", &temp.score[i]);
        sum += temp.score[i];
    }
    temp.ave = sum / 3.0;


    //开始寻找插入位置
    i = 0;
    while (i < 5 && temp.ave > students[i].ave)
    {
        i++;
    }
    n = i;
    if (n >= 5) {
        n = 4;
    }


    // 边打印边写入文件
    if ((fp = fopen(save_path,"w")) == NULL)
    {
        printf("文件写入失败！\n");
        return;
    }
    printf("新的数据文件为:\n");


    // 写入前面的数据
    for (i = 0; i <= n; i++)
    {
        if (fwrite(&students[i], sizeof(struct score_read_write_student),1, fp) != 1)
        {
            printf("数据写入失败！\n");
            return;
        }
        printf("NO.:%-4d  姓名：%-6s  成绩1:%5.f  成绩2:%5.f  成绩3:%5.f  平均成绩:%5.f\n",
               students[i].num, students[i].name, students[i].score[0], students[i].score[1],
               students[i].score[2], students[i].ave);
    }
    // 写入中间的数据
    if (fwrite(&temp, sizeof(struct score_read_write_student), 1, fp) != 1)
    {
        printf("数据写入失败！\n");
        return;
    }
    printf("NO.:%-4d  姓名：%-6s  成绩1:%5.f  成绩2:%5.f  成绩3:%5.f  平均成绩:%5.f\n",
           temp.num, temp.name, temp.score[0], temp.score[1],
           temp.score[2], temp.ave);

    // 写入剩余的数据
    for (;i < 5; i++)
    {
        if (fwrite(&students[i], sizeof(struct score_read_write_student), 1, fp) != 1)
        {
            printf("数据写入失败！\n");
            return;
        }
        printf("NO.:%-4d  姓名：%-6s  成绩1:%5.f  成绩2:%5.f  成绩3:%5.f  平均成绩:%5.f\n",
               students[i].num, students[i].name, students[i].score[0], students[i].score[1],
               students[i].score[2], students[i].ave);
    }
    printf("写入成功！\n");
    fclose(fp);
}







// 职工基本信息表
struct employee_table_read_write_employee_basic {
    int num;
    char name[20];
    char sex[6];
    int age;
    char health[10];
    char addr[30];
    int salary;
    char education[10];
};

// 职工工资表
struct employee_table_read_write_employee_salary {
    char name[20];
    int salary;
};

void employee_table_read_write() {
    int i, count = 4;
    FILE *fp1, *fp2;

    struct employee_table_read_write_employee_basic employee_table[4];
    struct employee_table_read_write_employee_salary employee_salary_table[4];

    const char* save_path1 = "/Users/apple/Desktop/employee_basic";
    const char* save_path2 = "/Users/apple/Desktop/employee_salary";

    // 建立职工基本信息文件
    if ((fp1 = fopen(save_path1,"w")) == NULL) {
        printf("文件写失败！\n");
        return;
    }


    for(i = 0; i < count; i++) {
        printf("**********请输入第%d个职工的数据**********\n",i+1);
        printf("工号:");
        scanf("%d", &employee_table[i].num);
        printf("姓名:");
        scanf("%s", &employee_table[i].name);
        printf("性别:");
        scanf("%s", &employee_table[i].sex);
        printf("年龄:");
        scanf("%d", &employee_table[i].age);
        printf("健康状况:");
        scanf("%s", &employee_table[i].health);
        printf("住址:");
        scanf("%s", &employee_table[i].addr);
        printf("学历:");
        scanf("%s", &employee_table[i].education);
        printf("薪水:");
        scanf("%d", &employee_table[i].salary);

        strcpy(employee_salary_table[i].name, employee_table[i].name);
        employee_salary_table[i].salary = employee_table[i].salary;

        if (fwrite(&employee_table[i], sizeof(struct employee_table_read_write_employee_basic),1, fp1) != 1) {
            printf("文件写入失败！\n");
            return;
        }
        printf("NO.:%d  姓名：%s  性别：%s  年龄：%2.d  健康：%s  住址：%s  学历：%s  工资：%5.d\n", employee_table[i].num, employee_table[i].name, employee_table[i].sex,
               employee_table[i].age, employee_table[i].health, employee_table[i].addr, employee_table[i].education, employee_table[i].salary);
    }

    // 将姓名与薪资整理成为新的数据文件保存
    if ((fp2 = fopen(save_path2, "w")) == NULL) {
        printf("name_salary 写入失败！\n");
        return;
    }
    for(i = 0;i < count; i++) {
        if (fwrite(&employee_salary_table[i], sizeof(struct employee_table_read_write_employee_salary), 1, fp2) != 1) {
            printf("name_salary 写入过程中失败！\n");
            return;
        }
        printf("姓名：%s  工资：%5.d\n", employee_salary_table[i].name, employee_salary_table[i].salary);
    }

    fclose(fp1);
    fclose(fp2);
}