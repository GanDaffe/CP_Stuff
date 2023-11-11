**Các khái niệm cần biết**:
+ `Chia để trị`: Là một tư tưởng giải bài tập, trong đó ta thực hiện theo 3 bước: Chia, Trị và Kết hợp.
	1. Chia: Cắt nhỏ bài toán lớn thành các bài toán con nhỏ hơn.
	2. Trị: Giải quyết các bài toán con. 
	3. Kết hợp: Ghép các bài toán nhỏ lại và cho ra kết quả bài toán lớn.
	Ví dụ: Quick Sort, Merge Sort...
+ `Range Query Problem`: Cho một mảng các đối tượng, đề bài yêu cầu tìm một đối tượng hoặc một kết quả nào đó trong một mảng con của mảng đầu vào.
	 Ví dụ: Tìm phần tử lớn nhất trong đoạn từ 1 – 3 của mảng {1, 3, -1, 0, 4, 6}
+ `Cây nhị phân đầy đủ`:  Là cây nhị phân mà mỗi node trong cây có chính xác 0 hoặc 2 con.

**Tại sao dùng `Segment Tree`?** 

   + Với các bài toán có số lượng phần tử lớn và số lượng query (truy vấn) nhiều, việc duyệt trâu bằng vòng lặp tỏ ra kém hiệu quả vì với mỗi truy vấn ta lại phải duyệt một khoảng trong mảng, điều này khiến độ phức tạp của thuật toán có thể bị đẩy lên O(n2) => Cần tìm ra một CTDL mang lại hiệu quả cao hơn.

**Ứng dụng**
+ Tìm Min, Max trong khoảng.
+ Tìm tổng các phần tử trong khoảng. 
+ Tìm kết quả của phép toán nào đó giữa các phần tử trong một khoảng.
    ...
  
**Segment Tree và các thành phần cơ bản**
+ Segment Tree hay cây phân đoạn về cơ bản là một cây nhị phân đầy đủ.
+ Mỗi Node là biểu diễn cho một đoạn của mảng, đoạn bé nhất bằng 1 (biểu diễn bởi các node lá).
+ Root Node biểu diễn cho cả mảng.  
+ Các Node chứa kết quả bài toán trong khoảng mà nó biểu diễn, bài toán có thể là tìm min, max...


**Cài đặt**
- Đầu tiên ta cần làm rõ số lượng node sẽ có trong tree. Gọi số lượng phần tử trong mảng đầu vào là n, dễ thấy số node cần để tạo nên segment tree sẽ là 2 * n – 1 (Chứng minh thông qua cấp số nhân)
- Để cho dễ hình dung, ta sẽ cài đặt cây phân đoạn trong 1 bài toán cụ thể: Tìm phần tử max trong các đoạn của mảng. 
- Ta sẽ sử dụng vector để lưu các node trong cây, như đã nói, cây sẽ có tổng là 2n – 1 node, trong đó n node sau của vector sẽ lưu các giá trị của mảng ban đầu, còn lại n – 1 node ở nửa trước sẽ lưu max cho các đoạn với độ rộng >= 2, càng về gần với index 0, thì đoạn biểu diễn sẽ càng rộng, chỉ số của root node (max của cả mảng) sẽ nằm tại index 1.
- Gồm tổng cộng 3 hàm: build(int arr[]), update(int p, int val), query(int l, int r) 

**Code**
```cpp
#include <bits/stdc++.h> 

using namespace std; 

// Bài toán: Tìm tổng của các đoạn con trong mảng

const int MAX = 1e4; //MAX SIZE của mảng đầu vào
int st[2 * MAX]; //MAX SIZE của cây phân đoạn 
int n; 

/* 
* Hàm build segment tree, không return giá trị. 
* @param arr[] Mảng đầu vào 
*/

void build(int arr[]) 
{
    // Build nửa sau của cây, mỗi node chỉ quản lý dữ liệu của chính nó
    for(int i = 0; i < n; i++) 
        st[n + i] = arr[i]; 

    // Build nửa sau của cây, mỗi node quản lý dữ liệu của 2 node con, mỗi node con lưu dữ liệu của một khoảng trong mảng.
    for(int i = n - 1; i > 0; i--)
        st[i] = st[2 * i] + st[2 * i + 1];
}

 /*
* Hàm cập nhật giá trị cho một node lá (chỉ quản lý dữ liệu của riêng nó) trong cây.
* @param val giá trị mới cho node được update.
* @param p Vị trí của node được update.
*/
void update(int val, int p) 
{
    st[p + n] = val; 
    p = p + n; 

    for(int i = p; i > 1; i /= 2) 
        st[i / 2] = st[i] + st[i ^ 1]; // Cập nhật các node có liên quan đến node bị thay đổi.

}

/*
* Hàm trả ra kết quả truy vấn trong một khoảng, return giá trị nguyên.
* @param l giới hạn bên trái của khoảng.
* @param r giới hạn bên phải của khoảng.
*/
int query(int l, int r) 
{
    int res = 0; 

    for(l += n, r += n; l < r; l /= 2, r /= 2) 
    {
        // Ở đây, nếu l & 1 == 1 tức là l có index lẻ, tương đương với việc node l đang là node con bên phải của node cha, nên node con bên trái của l không thuộc vào khoảng cần xét, ta dịch index của l sang phải 1 index.
        if(l & 1)
            res += st[l++]; 
        // Tương tự như trường hợp l, ta tính tổng [l, r), nên sẽ không lấy node r lẻ.
        if(r & 1)
            res += st[--r];
    }
    
    return res; 
}

int main() 
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; 

    n = sizeof(a)/sizeof(a[0]); 

    build(a);
    
    // Tổng [0, 3)
    cout << query(0, 3) << endl; 
    // Thay a[0] thành 5
    update(5, 0);
    // Tính lại tổng [0, 3) 
    cout << query(0, 3) << endl; 
    return 0;
}
```

