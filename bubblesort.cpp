#include <iostream>
using namespace std;

int DataArray[10] = { 0 };

void BubbleSort(int *DataArray, int Length) {

    for (int i = 0; i < Length - 1; i++) {
        //���� �������� ���� �ΰ� �� ������ �ʾƵ� �ȴ�.
        for (int j = 0; j < Length - (i + 1); j++) {
            //������ �����ʺ��� ũ��
            if (DataArray[j] > DataArray[j + 1])
                swap(DataArray[j + 1], DataArray[j]);
        }
    }
}

void InsertionSort(int *DataArray, int Length) {

    for (int i = 1; i < Length; i++) {
        // ���(1) (���1,2 ���� �ϳ��� �ּ�ó�� �ϼ���)

        /*
        // ������ �ʿ伺�� ���ٸ� ��ȸ �Ѿ��.
        if (DataArray[i - 1] <= DataArray[i]) continue;
        // ������ �ʿ䰡 ������ 1 ��° �����͸� value �� �־�д�.
        int value = DataArray[i];
        // value ���� ū ��Ҹ� ã�Ƴ������� ���ʺ��� �ٽ� �˻��Ѵ�.
        for (int j = 0; j < i; j++) {
            // value ���� ū ��Ҹ� ã�Ƴ���.
            if (DataArray[j] > value) {
                // ���⼭ memmove �Լ��� �޸� ���� �ű�� �Լ��Դϴ�.
                // �Ʒ� ������ �ؼ��ϸ�, &arrData[j] ���� sizeof(arrData[0]) * (i-j)��ŭ
                // &arrData[j+1]�� �̵��Ѵٴ� ���Դϴ�.
                memmove(&DataArray[j + 1], &DataArray[j], sizeof(DataArray[0])*(i - j));
                DataArray[j] = value;
                break;
            }
        }*/

        // ���(2)
        int key = DataArray[i];
        int j = i - 1;

        // ���� �����Ͱ� ������ �����ͺ��� ũ�ٸ�
        while (j >= 0 && key < DataArray[j]) {
            //���ʰ� �������� �ٲ۴�.
            swap(DataArray[j], DataArray[j + 1]);
            j--; // ������ �ٽ� Ȯ���ϱ� ���Ͽ�
        }
    }
}


void swap(int &i, int &j) {
    int tmp = i;
    i = j;
    j = tmp;
}
void print() {
    for (int i = 0; i < 10; i++)
    cout << DataArray[i] << " ";
    cout << endl;
}


int main() {
    //�����迭 �����
    for (int i = 0; i < 10; i++)
        DataArray[i] = rand() % 20;
    print();

    BubbleSort(DataArray, 10);
    print();
    cout << endl;


    for (int i = 0; i < 10; i++)
        DataArray[i] = rand() % 20;
    print();

    InsertionSort(DataArray, 10);
    print();
}
