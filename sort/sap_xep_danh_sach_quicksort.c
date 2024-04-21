// Viết chương trình nhập vào dãy n hồ sơ, thực hiện sắp xếp các hồ sơ theo thứ tự không giảm (ưu tiên so sánh họ tên trước, rồi mới đến ngày, tháng, năm sinh) bằng thuật toán sắp xếp nhanh 
// Input
// Dòng 2i-1 và dòng 2i (i = 1,…) tương ứng ghi họ tên (không dấu) và ngày, tháng, năm sinh của hồ sơ thứ i. Họ và tên ghi theo định dạng <họ> <tên đệm> <tên> và ngày, tháng, năm sinh ghi theo định dạng YYYY-MM-DD
// Dòng cuối cùng: ghi ký tự # thể hiện dấu hiệu kết thúc file
// Output
// Ghi dãy đã được sắp xếp theo thứ tự với định dạng
// Dòng 2i-1 và dòng 2i (i = 1,…) tương ứng ghi họ tên (không dấu) và ngày, tháng, năm sinh của hồ sơ thứ i. Họ và tên ghi theo định dạng <họ> <tên đệm> <tên> và ngày, tháng, năm sinh ghi theo định dạng YYYY-MM-DD
// Dòng cuối cùng: ghi ký tự # thể hiện dấu hiệu kết thúc file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ho[20];
    char tendem[20];
    char ten[20];
    int nam;
    int thang;
    int ngay;
} sinhvien;


int compare(const void *a, const void *b)
{
    sinhvien *sv1 = (sinhvien*) a;
    sinhvien *sv2 = (sinhvien*) b;

    int sosanhten= strcmp(sv1->ten, sv2->ten);
    if (  sosanhten != 0)
    {
        return sosanhten;
    }

    int sosanhtendem = strcmp(sv1->tendem, sv2->tendem);
    if ( sosanhtendem != 0)
    {
        return sosanhtendem;
    }

    int sosanhho = strcmp(sv1->ho, sv2->ho);
    if ( sosanhho != 0)
    {
        return sosanhho;
    }

    if ( sv1->nam != sv2->nam)
    {
        return sv2->nam - sv1->nam;
    }
    if ( sv1->ngay != sv2->ngay)
    {
        return sv2->ngay - sv1->ngay;
    }
    return sv2->thang - sv1->thang;
}


int main()
{
    sinhvien sv[100];
    int i = 0;
    while(1)
    {
        char text[10];
        scanf("%s", text);
        if ( text[0] == '#')
        {
            break;
        }
        strcpy( sv[i].ho, text);
        scanf("%s %s", sv[i].tendem, sv[i].ten);
        scanf("%d-%d-%d", &sv[i].nam, &sv[i].thang, &sv[i].ngay);
        i++;

    }

    qsort(sv, i, sizeof(sinhvien), compare);
    for (int j = 0; j<i; j++)
    {
        printf("%s %s %s\n", sv[j].ho, sv[j].tendem, sv[j].ten);
        printf ("%04d-%02d-%02d\n", sv[j].nam, sv[j].thang, sv[j].ngay);

    }
    printf("#");
    return 0;
}
