#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H

// 将字母写到文件，然后读取并打印
void write_string_to_file_then_read();

// 将字母读出来，排序后再写入新的文件
void read_from_files_then_sort_and_write();

// 输入学生数据并写到文件
void score_read_write();

// 学生数据排序
void read_score_sort_and_write();

// 已排序的学生文件中插入新的数据
void write_record_to_sorted_file();

// 建立职工信息文件并且导出相关信息到新文件
void employee_table_read_write();
#endif