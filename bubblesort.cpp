#include <iostream>
using namespace std;

int DataArray[10] = { 0 };

void BubbleSort(int *DataArray, int Length) {

    for (int i = 0; i < Length - 1; i++) {
        //가장 오른쪽의 원소 두개 는 비교하지 않아도 된다.
        for (int j = 0; j < Length - (i + 1); j++) {
            //왼쪽이 오른쪽보다 크면
            if (DataArray[j] > DataArray[j + 1])
                swap(DataArray[j + 1], DataArray[j]);
        }
    }
}

void InsertionSort(int *DataArray, int Length) {

    for (int i = 1; i < Length; i++) {
        // 방법(1) (방법1,2 둘중 하나를 주석처리 하세요)

        /*
        // 정렬할 필요성이 없다면 한회 넘어간다.
        if (DataArray[i - 1] <= DataArray[i]) continue;
        // 정렬할 필요가 있으면 1 번째 데이터를 value 에 넣어둔다.
        int value = DataArray[i];
        // value 보다 큰 요소를 찾아내기위해 왼쪽부터 다시 검색한다.
        for (int j = 0; j < i; j++) {
            // value 보다 큰 요소를 찾아낸다.
            if (DataArray[j] > value) {
                // 여기서 memmove 함수는 메모리 블럭을 옮기는 함수입니다.
                // 아래 문장을 해석하면, &arrData[j] 부터 sizeof(arrData[0]) * (i-j)만큼
                // &arrData[j+1]로 이동한다는 말입니다.
                memmove(&DataArray[j + 1], &DataArray[j], sizeof(DataArray[0])*(i - j));
                DataArray[j] = value;
                break;
            }
        }*/

        // 방법(2)
        int key = DataArray[i];
        int j = i - 1;

        // 왼쪽 데이터가 오른쪽 데이터보다 크다면
        while (j >= 0 && key < DataArray[j]) {
            //왼쪽과 오른쪽을 바꾼다.
            swap(DataArray[j], DataArray[j + 1]);
            j--; // 왼쪽을 다시 확인하기 위하여
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
    //난수배열 만들기
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
