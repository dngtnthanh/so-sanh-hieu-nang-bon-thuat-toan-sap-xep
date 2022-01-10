// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Sản phẩm đồ án 1
//Người thực hiện: Dương Tấn Thành
//Ngày hoàn thành 1/4/2020
//Giảng viên hướng dẫn: Thạc sĩ Nguyễn Thị Mỹ Dung
//Đề tài: Cài đặt bốn giải thuật sắp xếp và đánh giá hiệu năng
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>			//cấp phát động
#include <fstream>			//làm việc với file
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>			//cấp phát động
#include <windowsx.h>
#include <MMsystem.h>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <dos.h>
#include "console.h"
#include <ctime>


#pragma comment (lib , "winmm.lib")
using namespace std;

	int n;
	float a[99999];

	typedef struct {
		float ThoiGianThucThi;
		float Temp;
		float TBC;
	}KieuThuatToan;

	KieuThuatToan T_BubbleSort;
	KieuThuatToan T_InterchangeSort;
	KieuThuatToan T_SelectionSort;
	KieuThuatToan T_InsertionSort;


	void PhongChu() {
		HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
		PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX();
		font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
		GetCurrentConsoleFontEx(cons, 0, font);
		font->dwFontSize.X = 6;
		font->dwFontSize.Y = 22;
		//font->FontWeight = 22;
		//font->FontFamily = FF_DECORATIVE;
		SetCurrentConsoleFontEx(cons, 0, font);
	}
	

	void SetColor(int ForgC)
	{
		WORD wColor;

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		//We use csbi for the wAttributes word.
		if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
		{
			//Mask out all but the background attribute, and add in the forgournd     color
			wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
			SetConsoleTextAttribute(hStdOut, wColor);
		}
		return;
	}
	void Nhap(bool ss) {
		std::wcout << L"\n NHẬP VÀO BAO NHIÊU PHẦN TỬ: ";
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("wav/NhapN.wav"), NULL, SND_ASYNC);
		std::wcin >> n;
		for (int i = 0; i < n; i++) {
			std::wcout << L" PHẦN TỬ THỨ " << i << ":";
			std::wcin >> a[i];
		}
		if (ss == false){
			std::wcout << L" DÃY SỐ VỪA NHẬP LÀ: ";
			for (int i = 0; i < n; i++) {
				std::wcout << a[i] << " ";
			}
		}
		
		
	}
	void Random() {
		std::wcout << L"\n SỐ PHẦN TỬ CẦN TẠO: ";
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("wav/NhapN.wav"), NULL, SND_ASYNC);
		std::wcin >> n;
		srand((unsigned)time(NULL));
		for (int i = 0; i < n; i++) {
			a[i] = rand();
		}
		std::wcout << L" MẢNG ĐƯỢC TẠO: ";
		for (int i = 0; i < n; i++) {
			std::wcout << a[i] << " ";
		}
	}
	void Xuat(float t, bool SoSanh, bool XuatBT) {
		int XuatKQ;
		if (SoSanh == false) {
			
			std::wcout << L"\n\n THỜI GIAN SẮP XẾP DÃY SỐ LÀ ";
			SetColor(4);
			std::wcout<< t << "s";
			SetColor(0);
		}
		if (XuatBT == false)
		{
			std::wcout << L"\n\n BẠN CÓ MUỐN XUẤT KẾT QUẢ RA MÀN HÌNH KHÔNG?";
			std::wcout << L"\n [1] CÓ";
			std::wcout << L"\n [2] KHÔNG";
			std::wcout << L"\n BẠN CHỌN: ";
			PlaySound(NULL, NULL, SND_ASYNC);
			PlaySound(TEXT("wav/Xuatw.wav"), NULL, SND_ASYNC);
			std::wcin >> XuatKQ;
			if (XuatKQ == 1) {
				std::wcout << L"\n KẾT QUẢ: ";
				SetColor(4);
				for (int i = 0; i < n; i++) {
					std::wcout << a[i] << "\t";
					
				}
				SetColor(0);
			}
		}
		else
		{	
			
			std::wcout << L"\n KẾT QUẢ: ";
			SetColor(4);
			for (int i = 0; i < n; i++) {
				std::wcout << a[i] << " ";
			}
			SetColor(0);
		}
	}

	void sawp(float& xp, float& yp) {
		float temp = xp;
		xp = yp;
		yp = temp;
	}


	void XuatFile(float T) {
		int XuatKQFile;
		std::wcout << L"\n CHƯƠNG TRÌNH ĐÃ ĐƯỢC XỬ LÝ\n";
		std::wcout << L" DỮ LIỆU ĐƯỢC LẤY TỪ FILE inputVS.txt XỬ LÝ VÀ XUẤT RA FILE output_X.txt trong đó X là tên thuật toán\n";
		std::wcout << L" FILE inputVS.txt VÀ output_X.txt NẰM CÙNG THƯ MỤC CHỨA CHƯƠNG TRÌNH NÀY\n";
		std::wcout << L"\n - FILE CÓ TỔNG CỘNG " << n << L" PHẦN TỬ";
		std::wcout << L"\n - ĐÃ GHI KẾT QUẢ VÀO FILE output_X.txt THÀNH CÔNG. TRONG ĐÓ X LÀ TÊN THUẬT TOÁN";
		std::wcout << L"\n - THỜI GIAN SẮP XẾP DÃY SỐ LÀ " << T << "s";
		std::wcout << L"\n - BẠN CÓ MUỐN XUẤT KẾT QUẢ RA MÀN HÌNH KHÔNG?";
		std::wcout << L"\n 1. CÓ";
		std::wcout << L"\n 2. KHÔNG";
		std::wcout << L"\n BẠN CHỌN: ";
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("wav/Xuatw.wav"), NULL, SND_ASYNC);
		std::wcin >> XuatKQFile;
		if (XuatKQFile == 1) {
			std::wcout << L"\nDÃY SỐ SAU KHI ĐÃ ĐƯỢC SẮP XẾP: ";
			SetColor(4);
			for (int i = 0; i < n; i++) {
				std::wcout << a[i] << "\t";
			}
			SetColor(0);
		}
	}
	
	void TiengViet() {
		_setmode(_fileno(stdin), _O_U16TEXT);		//  Dùng để gán chuỗi ký tự Tiếng Việt
		_setmode(_fileno(stdout), _O_U16TEXT);		//  Dùng để xuất chuỗi ký tự Tiếng Việt ra màn hình console
		SetConsoleTitleW(L"Dương Tấn Thành | DHCNTT18 | Đồ án môn học 1");		//  Tên app console
		HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_FONT_INFOEX consoleFont;
		consoleFont.cbSize = sizeof(consoleFont);
		GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
		memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
		SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
	}
	void BubbleSort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = n - 1; j > i; j--) {
				if (a[j] < a[j - 1]) {
					sawp(a[j], a[j - 1]);
				}
			}
		}
	}
	void InterchangeSort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					float tg = a[j];
					a[j] = a[i];
					a[i] = tg;
				}
			}
		}
	}

	void SelectionSort() {
		int i, j, min_idx;
		for (i = 0; i < n - 1; i++)
		{
			min_idx = i;
			for (j = i + 1; j < n; j++)
				if (a[j] < a[min_idx])
					min_idx = j;
			sawp(a[min_idx], a[i]);
		}
	}
	void InsertionSort() {
		int pos, i;
		float key; 								//luu giá tri a[i] de tranh bi ghi de khi doi cho cac phan tu
		for (i = 1; i < n; i++)
		{
			key = a[i];
			pos = i - 1;
			//tim vi tri chen key
			while ((pos >= 0) && (a[pos] > key))//Ket hop doi cho cac phan tu se dung sau x trong day moi
			{
				a[pos + 1] = a[pos];
				pos--;
			}
			a[pos + 1] = key; 					// chèn key vào dãy
		}
	}

	void BubbleSortFile() {
		//Doc file
		std::ifstream file;
		file.open("inputVS.txt");
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> a[i];
		}

		clock_t start, end;					//tinh toan time thuc thi
		start = clock();

		BubbleSort();

		file.close();

		ofstream outfile; outfile.open("output_BubbleSort.txt");		//Ghi file
		outfile << "AP DUNG THUAT TOAN BubbleSort:\nFILE CO TONG CONG "<<n<<" PHAN TU"<<"\nKET QUA SAP XEP TU BE DEN LON:\n\n";
		for (int i = 0; i < n; i++) {
			outfile  << a[i] << " ";
		}
		outfile.close();

		end = clock();
		T_BubbleSort.ThoiGianThucThi = ((float)(end - start)) / CLOCKS_PER_SEC;
		
	}
	void InterchangeSortFile() {
		//Doc file
		std::ifstream file2;
		file2.open("inputVS.txt");
		file2 >> n;
		for (int i = 0; i < n; i++) {
			file2 >> a[i];
		}

		clock_t start, end;			//Tinh toan thoi gian thuc thi
		start = clock();

		InterchangeSort();

		file2.close();

		ofstream outfile2; outfile2.open("output_InterchangeSort.txt");		//Ghi file
		outfile2 << "AP DUNG THUAT TOAN InterchangeSort:\nFILE CO TONG CONG " << n << " PHAN TU" << "\nKET QUA SAP XEP TU BE DEN LON:\n\n";
		for (int i = 0; i < n; i++) {
			outfile2 << a[i] << " ";
		}
		outfile2.close();

		end = clock();
		T_InterchangeSort.ThoiGianThucThi = ((float)(end - start)) / CLOCKS_PER_SEC;
		
	}
	void SelectionSortFile() {
		//Doc file
		std::ifstream file3;
		file3.open("inputVS.txt");
		file3 >> n;
		for (int i = 0; i < n; i++) {
			file3 >> a[i];
		}

		clock_t start, end;					//tinh toan time thuc thi
		start = clock();

		SelectionSort();

		file3.close();

		
		ofstream outfile3; outfile3.open("output_SelectionSort.txt");		//Ghi file
		outfile3 << "AP DUNG THUAT TOAN SelectionSort:\nFILE CO TONG CONG " << n << " PHAN TU" << "\nKET QUA SAP XEP TU BE DEN LON:\n\n";
		for (int i = 0; i < n; i++) {
			outfile3 << a[i] << " ";
		}
		outfile3.close();

		end = clock();
		T_SelectionSort.ThoiGianThucThi = ((float)(end - start)) / CLOCKS_PER_SEC;


	}
	void InsertionSortFile() {
		//Doc file
		std::ifstream file4;
		file4.open("inputVS.txt");
		file4 >> n;

		for (int i = 0; i < n; i++) {
			file4 >> a[i];
		}

		clock_t start, end;					//tinh toan time thuc thi
		start = clock();

		InsertionSort();

		file4.close();

		ofstream outfile4; outfile4.open("output_InsertionSort.txt");		//Ghi file
		outfile4 << "AP DUNG THUAT TOAN InsertionSort:\nFILE CO TONG CONG " << n << " PHAN TU" << "\nKET QUA SAP XEP TU BE DEN LON:\n\n";
		for (int i = 0; i < n; i++) {
			outfile4 << a[i] << " ";
		}
		outfile4.close();

		end = clock();
		T_InsertionSort.ThoiGianThucThi = ((float)(end - start)) / CLOCKS_PER_SEC;
	}
	
	void TraVeKhong() {
		// Hàm trả về tất cả các dữ liệu người dùng tự định nghĩa về không. 
		T_BubbleSort.TBC = 0;
		T_InsertionSort.TBC = 0;
		T_InterchangeSort.TBC = 0;
		T_SelectionSort.TBC = 0;

		T_BubbleSort.Temp = 0;
		T_InsertionSort.Temp = 0;
		T_InterchangeSort.Temp = 0;
		T_SelectionSort.Temp = 0;

		T_BubbleSort.ThoiGianThucThi = 0;
		T_InsertionSort.ThoiGianThucThi = 0;
		T_InterchangeSort.ThoiGianThucThi = 0;
		T_SelectionSort.ThoiGianThucThi = 0;
	}
	void ChaoBatDau() {
		system("color B0");
		SetColor(0);
		std::wcout << L"\n\n\n\n\n=================================================  WELCOME  ==================================================\n\n\n\n\n";
		SetColor(4);
		std::wcout << L"                      CHƯƠNG TRÌNH ỨNG DỤNG CÁC GIẢI THUẬT SẮP XẾP VÀ ĐÁNH GIÁ HIỆU NĂNG    \n\n";
		SetColor(0);
		std::wcout << L"                                               *  *  *  *  *  *\n\n";
		std::wcout << L"                                          HỌ VÀ TÊN: DƯƠNG TẤN THÀNH\n\n";
		std::wcout << L"                                              MSSV: 0018413051\n\n";
		std::wcout << L"                                                LỚP: DHCNTT18  ";
		std::wcout << L"\n\n\n\n\n===========================================  SẢN PHẨM NỘP ĐỒ ÁN 1  ===========================================\n\n\n\n\n\n\n\n\n\n";
		PlaySound(TEXT("wav/ChaoBatDau"), NULL, SND_SYNC);

		system("color F0");
		
	}
	void ChuY() {
		std::wcout << L"\n\nCHÚ Ý: DỮ LIỆU INPUT NHẬP VÀO PHẢI RẤT LỚN ĐỂ CHƯƠNG TRÌNH SO SÁNH CHÍNH XÁC\n";
		PlaySound(TEXT("wav/ChuY.wav"), NULL, SND_SYNC);
	}
	

	void TheEnd() {
		system("cls");
		system("color B0");
		SetColor(0);
		std::wcout << L"\n\n\n\n\n===========================================  SẢN PHẨM NỘP ĐỒ ÁN 1  ===========================================\n\n\n";
		SetColor(4);
		std::wcout << L"                      CHƯƠNG TRÌNH ỨNG DỤNG CÁC GIẢI THUẬT SẮP XẾP VÀ ĐÁNH GIÁ HIỆU NĂNG    \n\n";
		SetColor(0);
		std::wcout << L"                                               *  *  *  *  *  *\n\n";
		std::wcout << L"                                          HỌ VÀ TÊN: DƯƠNG TẤN THÀNH\n\n";
		std::wcout << L"                                              MSSV: 0018413051\n\n";
		std::wcout << L"                                                LỚP: DHCNTT18  ";
		std::wcout << L"\n\n\n\n\n=================================================  THE END  ==================================================\n\n\n\n\n\n\n\n\n\n";
		PlaySound(NULL, NULL, SND_SYNC);
		PlaySound(TEXT("wav/ChaoKetThuc1.wav"), NULL, SND_SYNC);
	}

	void ThuatToanNhanhNhat() {
		float TBC[4] = { T_InterchangeSort.TBC, T_SelectionSort.TBC, T_InsertionSort.TBC, T_BubbleSort.TBC };
		float min = TBC[1];
	
		for (int i = 1; i < 4; ++i) {
			if (min > TBC[i]) {				//Do chưa ép kiểu dữ liệu.
				min = TBC[i];
			}
		}
		SetColor(4);
		if (T_InterchangeSort.TBC == min) {
			std::wcout << L"\n\n THUẬT TOÁN (Interchange Sort)  CHẠY NHANH NHẤT: " << min << "s";
		}
		else if (T_SelectionSort.TBC == min) {
			std::wcout << L"\n\n THUẬT TOÁN (Selection Sort) CHẠY NHANH NHẤT: " << min << "s";
		}
		else if (T_InsertionSort.TBC == min) {
			std::wcout << L"\n\n THUẬT TOÁN (Insertion Sort)  CHẠY NHANH NHẤT: " << min << "s";
		}
		else if (T_BubbleSort.TBC == min) {
			std::wcout << L"\n\n THUẬT TOÁN (Bubble Sort) CHẠY NHANH NHẤT: " << min << "s";
		}
		SetColor(0);
	}

	void SoSanh(float a[], int n) {
		std::wcout << L" \nBẠN MUỐN THỰC HIỆN SO SÁNH BAO NHIÊU LẦN: ";
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("wav/NhapSoLanSoSanh.wav"), NULL, SND_ASYNC);
		std::wcin >> n;
		std::wcout << L"\n\t\t\t\t\tBẢNG SO SÁNH\n\n";
		std::wcout << "_____________________________________________________________________________________________\n";
		std::wcout << L"THUẬT TOÁN\t|" << "BubbleSort\t" << "InterchangeSort\t\t" << "SelectionSort\t\t" << "InsertionSort" << "\n";		//Tao danh muc bang
		std::wcout << "_____________________________________________________________________________________________\n";
		for (int i = 1; i <= n; i++) {

			BubbleSort();
			InterchangeSort();
			SelectionSort();
			InsertionSort();
			T_BubbleSort.Temp = T_BubbleSort.Temp + T_BubbleSort.ThoiGianThucThi;
			T_InterchangeSort.Temp = T_InterchangeSort.Temp + T_InterchangeSort.ThoiGianThucThi;
			T_SelectionSort.Temp = T_SelectionSort.Temp + T_SelectionSort.ThoiGianThucThi;
			T_InsertionSort.Temp = T_InsertionSort.Temp + T_InsertionSort.ThoiGianThucThi;

			std::wcout << L" LẦN " << i << "(s) \t|" << T_BubbleSort.ThoiGianThucThi << "\t\t" << T_InterchangeSort.ThoiGianThucThi << "\t\t\t" << T_SelectionSort.ThoiGianThucThi << "\t\t\t" << T_InsertionSort.ThoiGianThucThi << "\n";			//Xuat ket qua ra danh sach
			std::wcout << "_____________________________________________________________________________________________\n";
		}
		T_BubbleSort.TBC = T_BubbleSort.Temp / n;
		T_InterchangeSort.TBC = T_InterchangeSort.Temp / n;
		T_SelectionSort.TBC = T_SelectionSort.Temp / n;
		T_InsertionSort.TBC = T_InsertionSort.Temp / n;
		std::wcout << L"TRUNG BÌNH CỘNG\t|" << T_BubbleSort.TBC << "\t\t" << T_InterchangeSort.TBC << "\t\t\t" << T_SelectionSort.TBC << "\t\t\t" << T_InsertionSort.TBC << "\n";
		std::wcout << "_____________________________________________________________________________________________\n";
		std::wcout << L"\n\n DỮ LIỆU ĐƯỢC LẤY TỪ FILE inputVS.txt XỬ LÝ VÀ XUẤT RA FILE output_X.txt trong đó X là tên thuật toán\n";
		std::wcout << L" FILE inputVS.txt VÀ output_X.txt NẰM CÙNG THƯ MỤC CHỨA CHƯƠNG TRÌNH NÀY\n";
		ThuatToanNhanhNhat();
		TraVeKhong();
	}

	void SoSanhFile() {
		int n;
		std::wcout << L" \nBẠN MUỐN THỰC HIỆN SO SÁNH BAO NHIÊU LẦN: ";
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("wav/NhapSoLanSoSanh.wav"), NULL, SND_ASYNC);
		std::wcin >> n;
		std::wcout << L"\n\t\t\t\t\tBẢNG SO SÁNH\n\n";
		std::wcout << "_____________________________________________________________________________________________\n";
		std::wcout << L"THUẬT TOÁN\t|" << "BubbleSort\t" << "InterchangeSort\t\t" << "SelectionSort\t\t" << "InsertionSort" << "\n";		//Tao danh muc bang
		std::wcout << "_____________________________________________________________________________________________\n";
		for (int i = 1; i <= n; i++) {

			BubbleSortFile();
			InterchangeSortFile();
			SelectionSortFile();
			InsertionSortFile();
			T_BubbleSort.Temp = T_BubbleSort.Temp + T_BubbleSort.ThoiGianThucThi;
			T_InterchangeSort.Temp = T_InterchangeSort.Temp + T_InterchangeSort.ThoiGianThucThi;
			T_SelectionSort.Temp = T_SelectionSort.Temp + T_SelectionSort.ThoiGianThucThi;
			T_InsertionSort.Temp = T_InsertionSort.Temp + T_InsertionSort.ThoiGianThucThi;

			std::wcout << L" LẦN " << i << "(s) \t|" << T_BubbleSort.ThoiGianThucThi << "\t\t" << T_InterchangeSort.ThoiGianThucThi << "\t\t\t" << T_SelectionSort.ThoiGianThucThi << "\t\t\t" << T_InsertionSort.ThoiGianThucThi << "\n";			//Xuat ket qua ra danh sach
			std::wcout << "_____________________________________________________________________________________________\n";
		}
		T_BubbleSort.TBC = (T_BubbleSort.Temp / n);
		T_InterchangeSort.TBC = (T_InterchangeSort.Temp / n);
		T_SelectionSort.TBC = (T_SelectionSort.Temp / n);
		T_InsertionSort.TBC = (T_InsertionSort.Temp / n);
		std::wcout << L"TRUNG BÌNH CỘNG\t|" << T_BubbleSort.TBC << "\t\t" << T_InterchangeSort.TBC << "\t\t\t" << T_SelectionSort.TBC << "\t\t\t" << T_InsertionSort.TBC << "\n";
		std::wcout << "_____________________________________________________________________________________________\n";
		std::wcout << L"\n\n DỮ LIỆU ĐƯỢC LẤY TỪ FILE inputVS.txt XỬ LÝ VÀ XUẤT RA FILE output_X.txt trong đó X là tên thuật toán\n";
		std::wcout << L" FILE inputVS.txt VÀ output_X.txt NẰM CÙNG THƯ MỤC CHỨA CHƯƠNG TRÌNH NÀY\n";
		ThuatToanNhanhNhat();
		TraVeKhong();
		
		
	}
	void Menu() {
		system("cls");
		std::wcout << "\n\n\n==============================  MENU  ==============================\n";
		SetColor(4);
		     std::wcout << L"   CHƯƠNG TRÌNH ỨNG DỤNG GIẢI THUẬT SẮP XẾP VÀ ĐÁNH GIÁ HIỆU NĂNG " << std::endl;
			 std::wcout << L"                             *  *  *  *\n\n";
		SetColor(0);
		std::wcout << L"\n\t [1] SẮP XẾP NỔI BỌT    (Bubble Sort)";
		std::wcout << L"\n\n\t [2] ĐỔI CHỖ TRỰC TIẾP  (Interchange Sort)";
		std::wcout << L"\n\n\t [3] SẮP XẾP CHỌN       (Selection Sort)";
		std::wcout << L"\n\n\t [4] SẮP XẾP CHÈN       (Insertion Sort)";
		std::wcout << L"\n\n\t [5] SO SÁNH HIỆU NĂNG CẢ BỐN THUẬT TOÁN";
		std::wcout << L"\n\n\t [0] THOÁT CHƯƠNG TRÌNH!!!\n\n";
		std::wcout << "====================================================================\n";
		PlaySound(TEXT("wav/Menu.wav"), NULL, SND_ASYNC);
		}
		
	void Menu2() {
		
		PlaySound(NULL, NULL, SND_ASYNC);
		PlaySound(TEXT("wav/Menu2"), NULL, SND_ASYNC);
		std::wcout << "\n\n\n========================= MENU ========================\n\n";
		std::wcout << L" \t[1] NHẬP DÃY SỐ TỰ CHỌN\n\n";
		std::wcout << L" \t[2] LẤY DỮ LIỆU TỪ FILE BÊN NGOÀI\n\n";
		std::wcout << L" \t[3] CẤP PHÁT ĐỘNG RANDOM\n";
		std::wcout << "\n\n=======================================================\n\n";
	}
	int ChonMenu()
	{
		int n = 0;
		std::wcout << L"\n\n BẠN CHỌN TÍNH NĂNG: ";
		std::wcin >> n;
		if (n > -1 || n < 99)
			return n;
		else
			std::wcout << L" MỜI BẠN NHẬP LẠI SỐ THÍCH HỢP!";
		return ChonMenu();
	}
	void XuLyMenu() {
		int TiepTuc;
		ChaoBatDau();
		do {
			Menu();
			int chon = ChonMenu();
			system("cls");
			switch (chon)
			{

			case 1:
				SetColor(4);
				std::wcout << L"\n  BẠN CHỌN THUẬT TOÁN SẮP XẾP NỔI BỌT (Bubble Sort)";
				SetColor(0);
				Menu2();
				chon = ChonMenu();
				switch (chon)
				{
				case 1:
					Nhap(false);
					BubbleSort();
					Xuat(T_BubbleSort.ThoiGianThucThi, false, true);
					break;
				
				case 2:
					BubbleSortFile();
					XuatFile(T_BubbleSort.ThoiGianThucThi);
					break;
				case 3:
					Random();
					BubbleSort();
					Xuat(T_BubbleSort.ThoiGianThucThi, false, true);
					break;
				}
				break;
			case 2:
				SetColor(4);
				std::wcout << L"\n  BẠN CHỌN THUẬT TOÁN ĐỔI CHỖ TRỰC TIẾP (Interchange Sort)";
				SetColor(0);
				Menu2();
				chon = ChonMenu();
				switch (chon)
				{
				case 1:
					Nhap(false);
					InterchangeSort();
					Xuat(T_InterchangeSort.ThoiGianThucThi, false, true);
					break;
				case 2:
					InterchangeSortFile();
					XuatFile(T_InterchangeSort.ThoiGianThucThi);
					break;
				case 3:
					Random();
					InterchangeSort();
					Xuat(T_InterchangeSort.ThoiGianThucThi, false, true);
					break;
				}
				break;
			case 3:
				SetColor(4);
				std::wcout << L"\n  BẠN CHỌN THUẬT TOÁN SẮP XẾP CHỌN (Selection Sort)";
				SetColor(0);
				Menu2();
				chon = ChonMenu();
				switch (chon)
				{
				case 1:
					Nhap(false);
					SelectionSort();
					Xuat(T_SelectionSort.ThoiGianThucThi, false, true);
					break;
				case 2:
					SelectionSortFile();
					XuatFile(T_SelectionSort.ThoiGianThucThi);
					break;
				case 3:
					Random();
					SelectionSort();
					Xuat(T_SelectionSort.ThoiGianThucThi, false, true);
					break;
				}
				break;
			case 4:
				SetColor(4);
				std::wcout << L"\n  BẠN CHỌN THUẬT TOÁN SẮP XẾP CHÈN (Insertion Sort)";
				SetColor(0);
				Menu2();
				chon = ChonMenu();
				switch (chon)
				{
				case 1:
					Nhap(false);
					InsertionSort();
					Xuat(T_InsertionSort.ThoiGianThucThi, false, true);
					break;
				case 2:
					InsertionSortFile();
					XuatFile(T_InsertionSort.ThoiGianThucThi);
					break;
				case 3:
					Random();
					InsertionSort();
					Xuat(T_InsertionSort.ThoiGianThucThi, false, true);
					break;
				}
				break;
			case 5:
				Menu2();
				chon = ChonMenu();
				switch (chon)
				{
				case 1:
					TraVeKhong();
					ChuY();
					Nhap(true);
					SoSanh(a, n);
					Xuat(0, true, false);
					break;
				case 2:
					TraVeKhong();
					SoSanhFile();
					break;
				case 3:
					TraVeKhong();
					Random();
					SoSanh(a, n);
				}
				break;
			case 0:
				TheEnd();
				exit(1);
				break;
			default:
				SetColor(4);
				std::wcout << L"\n\n\n\n\n\n\n                             BẠN VỪA NHẬP KHÔNG CHÍNH XÁC";
				SetColor(0);
			}
			std::wcout << L"\n\n NHẤN PHÍM 1 ĐỂ QUAY LẠI MENU, NHẤN PHÍM BẤT KỲ ĐỂ THOÁT CHƯƠNG TRÌNH: ";
			PlaySound(NULL, NULL, SND_ASYNC);
			PlaySound(TEXT("wav/NhanDeThoat.wav"), NULL, SND_ASYNC);
			std::wcin >> TiepTuc;
			system("cls");
		} while (TiepTuc == 1);
		TheEnd();
		exit(1);
	}

	int main(int argc, char* argv[])
	{

		TiengViet();
		PhongChu();
		XuLyMenu();
		return 0;

	}
   
  


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
