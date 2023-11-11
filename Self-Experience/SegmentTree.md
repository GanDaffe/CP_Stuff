Các khái niệm cần biết:
+ Chia để trị: Là một tư tưởng giải bài tập, trong đó ta thực hiện theo 3 bước: Chia, Trị và Kết hợp.
	1. Chia: Cắt nhỏ bài toán lớn thành các bài toán con nhỏ hơn.
	2. Trị: Giải quyết các bài toán con. 
	3. Kết hợp: Ghép các bài toán nhỏ lại và cho ra kết quả bài toán lớn.
	Ví dụ: Quick Sort, Merge Sort...
+ Range Query Problem: Cho một mảng các đối tượng, đề bài yêu cầu tìm một đối tượng hoặc một kết quả nào đó trong một mảng con của mảng đầu vào.
	 Ví dụ: Tìm phần tử lớn nhất trong đoạn từ 1 – 3 của mảng {1, 3, -1, 0, 4, 6}
+ Cây nhị phân đầy đủ:  Là cây nhị phân mà mỗi node trong cây có chính xác 0 hoặc 2 con.

Tại sao dùng Segment Tree? 
   Với các bài toán có số lượng phần tử lớn và số lượng query (truy vấn) nhiều, việc duyệt trâu bằng vòng lặp tỏ ra kém hiệu quả vì với mỗi truy vấn ta lại phải duyệt một khoảng trong mảng, điều này khiến độ phức tạp của thuật toán có thể bị đẩy lên O(n2) => Cần tìm ra một CTDL mang lại hiệu quả cao hơn.

Ứng dụng 
+ Tìm Min, Max trong khoảng.
+ Tìm tổng các phần tử trong khoảng. 
+ Tìm kết quả của phép toán nào đó giữa các phần tử trong một khoảng.
    ... 
Segment Tree và các thành phần cơ bản
+ Segment Tree hay cây phân đoạn về cơ bản là một cây nhị phân đầy đủ.
+ Mỗi Node là biểu diễn cho một đoạn của mảng, đoạn bé nhất bằng 1 (biểu diễn bởi các node lá).
+ Root Node biểu diễn cho cả mảng.  
+ Các Node chứa kết quả bài toán trong khoảng mà nó biểu diễn, bài toán có thể là tìm min, max...


Cài đặt
+ Đầu tiên ta cần làm rõ số lượng node sẽ có trong tree. Gọi số lượng phần tử trong mảng đầu vào là n, dễ thấy số node cần để tạo nên segment tree sẽ là 2 * n – 1. Chứng minh qua cấp số nhân: 
	SL =  n + n / 2 + n / 4 + ...  + 2  + 1 = > cấp số nhân với u = 1 và q = 2
	Gọi x là số lần nhân ta có: 
		n = 2 x – 1
	 	log2n = x - 1 
	 	log22n = x
	Mà SL = 1 *  (1 – 2 x) / 1 – 2 
	 	SL =  - 1  + 2 log22n 
`		SL + 1 = 2 log22n
	 	log2 (SL + 1)= log22n
	 	SL = 2n – 1 (Done)

+ Để cho dễ hình dung, ta sẽ cài đặt cây phân đoạn trong 1 bài toán cụ thể: Tìm phần tử max trong các đoạn 1 – 2, 1 – 3, 4 – 7 của mảng {1, 2, 0, 3, 8, 6, 9} 
+ Ta sẽ sử dụng vector để lưu các node trong cây, như đã nói, cây sẽ có tổng là 2n – 1 node, trong đó n node sau của vector sẽ lưu các giá trị của mảng ban đầu, còn lại n – 1 node ở nửa trước sẽ lưu max cho các đoạn với độ rộng >= 2, càng về gần với index 0, thì đoạn biểu diễn sẽ càng rộng, chỉ số của root node (max của cả mảng) sẽ nằm tại index 1.
+ Gồm tổng cộng 3 hàm: build(int arr[]), update(int p, int val), query(int l, int r) 
+ Code:

