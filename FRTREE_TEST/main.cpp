#include <iostream>

using namespace std;

template<class T>
class FRactTree {
private:
	class TNode {
	public:
		T data;
		TNode* parent;
		TNode* desc1;
		TNode* desc2;
		TNode* desc3;
		TNode* desc4;
		TNode* desc5;
		TNode* desc6;
		TNode* desc7;
		TNode* desc8;
		TNode* next_inlist;
		int number_inlist;
	public:
		TNode(T data, int num) {
			this->data = data;
			this->parent = nullptr;
			this->desc1 = nullptr;
			this->desc2 = nullptr;
			this->desc3 = nullptr;
			this->desc4 = nullptr;
			this->desc5 = nullptr;
			this->desc6 = nullptr;
			this->desc7 = nullptr;
			this->desc8 = nullptr;
			this->next_inlist = nullptr;
			this->number_inlist = num;
		}
		~TNode(){

		}
	};
public:
	TNode* root;
	TNode* cur;
	TNode* list_head;
	TNode* list_last;
	TNode* cur_inlist;
	TNode* auxl_pos;
	int amount_of_layers;
	int list_size;

	FRactTree() {
		this->root = nullptr;
		this->cur = nullptr;
		this->cur_inlist = nullptr;
		this->list_head = nullptr;
		this->list_last = nullptr;
		this->auxl_pos = nullptr;
		this->amount_of_layers = 0;
		this->list_size = 0;
	}
	bool isEmpty()
	{
		return list_head == nullptr;
	}
	void push_back(T elem,int n)
	{
		TNode* newElem = new TNode(elem,n);
		
		if (isEmpty())
		{
			list_head = newElem;
		}
		else
		{
			list_last->next_inlist = newElem;
		}
		list_last = newElem;
	}
	void go_to_elem_in_list(int num) {
		if (num > list_size) {
			num = list_size;
		}
		cur_inlist = list_head;
		for (int i = 1; i < num + 1; i++) {
			cur_inlist = cur_inlist->next_inlist;
		}
	}
	void set_auxl_pos(int num) {
		if (num > list_size) {
			num = list_size;
		}
		auxl_pos = list_head;
		for (int i = 1; i < num + 1; i++) {
			auxl_pos = auxl_pos->next_inlist;
		}
	}
	void SetTreeList(int layers_amount, T data) {
		amount_of_layers = layers_amount;
		if (layers_amount >= 1) {
			int elements = 1;
			if (layers_amount >= 2) {
				elements += 4;
				if (layers_amount >= 3) {
					int K = 4;
					for (int i = 0; i < layers_amount - 2; i++) {
						K = K * 8;
						elements += K;
					}
					
				}
			}
			for (int j = 0; j < elements; j++) {
				push_back(data,j);
			}
			list_size = elements;
			cout << list_size<<'\n';
		}
		cur = root;
		
		
	}
	void SetConnections() {
		if (amount_of_layers >= 1) {
			root = list_head; cur_inlist = list_head; 
			if (amount_of_layers >= 2) {
				go_to_elem_in_list(1);
				root->desc1 = cur_inlist; cur_inlist->parent = root; 
				go_to_elem_in_list(2);
				root->desc2 = cur_inlist; cur_inlist->parent = root;
				go_to_elem_in_list(3);
				root->desc3 = cur_inlist; cur_inlist->parent = root;
				go_to_elem_in_list(4);
				root->desc4 = cur_inlist; cur_inlist->parent = root;
				if (amount_of_layers >= 3) {
					int skip_to_parent = 1;
					int parent_amount = 4;
					int skip_to_desc = skip_to_parent + parent_amount;
					for (int g = 0; g < amount_of_layers - 2; g++) {
						
						for (int i = 1; i < parent_amount + 1; i++) {
							set_auxl_pos(i + skip_to_parent - 1); 
							go_to_elem_in_list(skip_to_desc );//1 
							cout << cur_inlist->number_inlist << '\n';
							auxl_pos->desc1 = cur_inlist; cur_inlist->parent = auxl_pos;
							go_to_elem_in_list(skip_to_desc + 1);//2
							auxl_pos->desc2 = cur_inlist; cur_inlist->parent = auxl_pos;
							go_to_elem_in_list(skip_to_desc + 2);//3
							auxl_pos->desc3 = cur_inlist; cur_inlist->parent = auxl_pos;
							go_to_elem_in_list(skip_to_desc + 3);//4
							auxl_pos->desc4 = cur_inlist; cur_inlist->parent = auxl_pos;
							go_to_elem_in_list(skip_to_desc + 4);//5
							auxl_pos->desc5 = cur_inlist; cur_inlist->parent = auxl_pos;
							go_to_elem_in_list(skip_to_desc + 5);//6
							auxl_pos->desc6 = cur_inlist; cur_inlist->parent = auxl_pos;
							go_to_elem_in_list(skip_to_desc + 6);//7
							auxl_pos->desc7 = cur_inlist; cur_inlist->parent = auxl_pos;
							go_to_elem_in_list(skip_to_desc + 7);//8
							auxl_pos->desc8 = cur_inlist; cur_inlist->parent = auxl_pos;
						}

						skip_to_parent = skip_to_desc;
						parent_amount = parent_amount * 8;
						skip_to_desc = skip_to_parent + parent_amount;
					}
					

				}
			}
		}
		cur = root;
	}
	void set_data(T newdata) {
		cur->data = newdata;
	}
	T get_data() {
		return cur->data;
	}
};
//


int Type_first_to_second(int X1,int Y1,int X2, int Y2) {
	int Cx, Cy;
	Cx = X2 - X1;
	Cy = Y2 - Y1;
	if (Cx < 0 and Cy == 0) {
		return 1;
	}
	else {
		if (Cx == 0 and Cy > 0) {
			return 2;
		}
		else {
			if (Cx > 0 and Cy==0) {
				return 3;
			}
			else {
				if (Cx == 0 and Cy < 0) {
					return 4;
				}
			}
		}
	}
}

int** COOR_COUNT(int x0,int y0, int layers_amount, int col_amount) {
	if (layers_amount < 1) {
		layers_amount = 1;
	}
	int color_count = 1;
	int cube_l=4; 
	for (int i = 0; i < layers_amount - 1; i++) {
		cube_l *= 4;
	}//задание размеров куба
	const int size_one = 7;
	const int size_two = 3;
	FRactTree<int**>* TestTree = new FRactTree<int**>();
	int** arr = new int* [size_one];
	for (int count = 0; count < size_one; count++) {
		arr[count] = new int[size_two];
	}
	TestTree->SetTreeList(layers_amount, arr);
	int coor_amount = 0;
	if (layers_amount == 1) {
		coor_amount = 4;
	}
	else {
		if (layers_amount == 2) {
			coor_amount = 4;
		}
		else {
			if (layers_amount >= 3) {
				coor_amount = 4;
				for (int k = 0; k < layers_amount - 2; k++) {
					coor_amount *= 8;
				}
			}
		}
		coor_amount = coor_amount * 8;
	}
	
	int** to_print = new int* [coor_amount];
	cout << coor_amount << '\n';
	for (int i = 0; i < coor_amount; i++) {
		to_print[i] = new int[3];
	}
	for (int i = 0; i < coor_amount; i++) {
		for (int j = 0; j < 3; j++) {
			to_print[i][j] = -10000;
		}
	}
	
	
	//TestTree->SetConnections();
	//задание дерева
	if (layers_amount >= 1) {
		int A1x, A2x, A3x, A4x, A1y, A2y, A3y, A4y;
		A1x = x0 + cube_l / 2; A1y = y0 - cube_l / 2;
		A2x = x0 - cube_l / 2; A2y = y0 - cube_l / 2;
		A3x = x0 - cube_l / 2; A3y = y0 + cube_l / 2;
		A4x = x0 + cube_l / 2; A4y = y0 + cube_l / 2;
		//
		arr = new int* [size_one];
		for (int count = 0; count < size_one; count++) {
			arr[count] = new int[size_two];
		}
		//реинициализация массива координат
		arr[0][0] = A1x; arr[0][1] = A1y; arr[0][2] = color_count;
		arr[1][0] = A2x; arr[1][1] = A2y; arr[1][2] = color_count;
		arr[2][0] = A3x; arr[2][1] = A3y; arr[2][2] = color_count;
		arr[3][0] = A4x; arr[3][1] = A4y; arr[3][2] = color_count;
		
		arr[4][0] = 1000; arr[4][1] = 1000; arr[4][2] = color_count;
		arr[5][0] = 1000; arr[5][1] = 1000; arr[5][2] = color_count;
		arr[6][0] = 1000; arr[6][1] = 1000; arr[6][2] = color_count;
		TestTree->cur = TestTree->list_head;
		TestTree->cur_inlist = TestTree->list_head;
		TestTree->set_data(arr);
		if (layers_amount >= 2) {
			int** getarr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				getarr[count] = new int[size_two];
			}
			TestTree->cur = TestTree->list_head;
			getarr = TestTree->get_data();
			int direction=0;
			int dx1, dx2, dx3, dx4, dx5, dx6, dx7, dy1, dy2, dy3, dy4, dy5, dy6, dy7;
			int col_f, col_rest;
			col_f = getarr[0][2]; col_rest = getarr[0][2] + 1;
			//dir=1
			int X1 = getarr[0][0]; int Y1 = getarr[0][1];
			int X2 = getarr[1][0]; int Y2 = getarr[1][1];
			int L = X1 - X2; 
			dx1 = X1 - (L / 4); dx2 = dx1;
			dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
			dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
			dy1 = Y2; dy4 = dy1; dy7 = dy1;
			dy2 = Y2 + (L / 4); dy3 = dy2;
			dy5 = Y2 - (L / 4); dy6 = dy5;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1;
			arr[1][0] = dx2; arr[1][1] = dy2;
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5;
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			//dir=2
			X1 = getarr[1][0]; Y1 = getarr[1][1];
			X2 = getarr[2][0]; Y2 = getarr[2][1];
			L = Y2 - Y1;
			dx5 = X1 - (L / 4); dx6 = dx5;
			dx1 = X1; dx4 = dx1; dx7 = dx1;
			dx2 = X1 + (L / 4); dx3 = dx2;
			dy1 = Y1 + (L / 4); dy2 = dy1;
			dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
			dy6 = Y1 + ((L*3)/ 4); dy7 = dy6;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1;
			arr[1][0] = dx2; arr[1][1] = dy2;
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5;
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			//dir=3
			
			X1 = getarr[2][0]; Y1 = getarr[2][1];
			X2 = getarr[3][0]; Y2 = getarr[3][1];
			L = X2 - X1;
			dx1 = X1 + L / 4; dx2 = dx1;
			dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
			dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
			dy1 = Y1; dy4 = dy1; dy7 = dy1;
			dy2 = Y1 - L / 4; dy3 = dy2;
			dy5 = Y1 + L / 4; dy6 = dy5;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1;
			arr[1][0] = dx2; arr[1][1] = dy2;
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5;
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			//dir=4
			
			X1 = getarr[3][0]; Y1 = getarr[3][1];
			X2 = getarr[0][0]; Y2 = getarr[0][1];
			L = Y1 - Y2; 
			dx5 = X2 + L / 4; dx6 = dx5;
			dx1 = X2; dx4 = dx1; dx7 = dx1;
			dx2 = X2 - L / 4; dx3 = dx2;
			dy1 = Y1 - L / 4; dy2 = dy1;
			dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
			dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1; 
			arr[1][0] = dx2; arr[1][1] = dy2; 
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5; 
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			if (layers_amount >= 3) {
				int skip_to_parent = 1;
				int parent_amount = 4;
				int skip_to_desc = skip_to_parent + parent_amount;
				int col_fase = 3;
				for (int g = 0; g < layers_amount - 2; g++) {
					
					for (int i = 0; i < parent_amount; i++) {
						TestTree->set_auxl_pos(i + skip_to_parent);
						TestTree->cur = TestTree->auxl_pos;
						getarr = TestTree->get_data();
						col_f = getarr[0][2];
						col_rest = getarr[1][2];
						int dir18;
						int dir;
						dir18 = Type_first_to_second(getarr[0][0], getarr[0][1], getarr[6][0], getarr[6][1]);
						int Stx=0, Sty=0, Etx=0, Ety=0;
						if (dir18 == 1) {
							L = (getarr[0][0] - getarr[6][0]) / 2; 
							Stx = getarr[0][0] + L; Sty = getarr[0][1];
							Etx = getarr[6][0] - L; Ety = Sty;
							
						}else{
							if (dir18 == 2) {
								L = (getarr[6][1] - getarr[0][1]) / 2;
								Stx = getarr[0][0]; Sty = getarr[0][1] - L;
								Etx = Stx; Ety = getarr[6][1] + L;
								
							}else {
								if (dir18 == 3) {
									L = (getarr[6][0] - getarr[0][0]) / 2;
									Stx = getarr[0][0] - L; Sty = getarr[0][1];
									Etx = getarr[6][0] + L; Ety = Sty;
									
								}else {
									if (dir18 == 4) {
										L = (getarr[0][1] - getarr[6][1]) / 2;
										Stx = getarr[0][0]; Sty = getarr[0][1] + L;
										Etx = Stx; Ety = getarr[6][1] - L;
										
									}
								}
							}
						}
						
						//1
						TestTree->go_to_elem_in_list(skip_to_desc);
						TestTree->cur = TestTree->cur_inlist;
						X1 = Stx; Y1 = Sty; X2 = getarr[0][0]; Y2 = getarr[0][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2); 
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 - (L / 4); dy3 = dy2;
							dy5 = Y2 + (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_f;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_f;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_f;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_f;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//2
						TestTree->go_to_elem_in_list(skip_to_desc+1);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[0][0]; Y1 = getarr[0][1]; X2 = getarr[1][0]; Y2 = getarr[1][1]; 
						dir = Type_first_to_second(X1, Y1, X2, Y2); 
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//3
						TestTree->go_to_elem_in_list(skip_to_desc + 2);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[1][0]; Y1 = getarr[1][1]; X2 = getarr[2][0]; Y2 = getarr[2][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//4
						TestTree->go_to_elem_in_list(skip_to_desc + 3);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[2][0]; Y1 = getarr[2][1]; X2 = getarr[3][0]; Y2 = getarr[3][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//5
						TestTree->go_to_elem_in_list(skip_to_desc + 4);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[3][0]; Y1 = getarr[3][1]; X2 = getarr[4][0]; Y2 = getarr[4][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//6
						TestTree->go_to_elem_in_list(skip_to_desc + 5);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[4][0]; Y1 = getarr[4][1]; X2 = getarr[5][0]; Y2 = getarr[5][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//7
						TestTree->go_to_elem_in_list(skip_to_desc + 6);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[5][0]; Y1 = getarr[5][1]; X2 = getarr[6][0]; Y2 = getarr[6][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//8
						TestTree->go_to_elem_in_list(skip_to_desc + 7);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[6][0]; Y1 = getarr[6][1]; X2 = Etx; Y2 = Ety; 
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_f;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_f;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_f;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_f;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//
						skip_to_desc += 8;
					}
					col_fase++;
					skip_to_parent = skip_to_parent+parent_amount;
					parent_amount = parent_amount * 8;
					//skip_to_desc = skip_to_parent + parent_amount;
				}


			}

		}
		int** readarr = new int* [size_one];
		for (int count = 0; count < size_one; count++) {
			readarr[count] = new int[size_two];
		}
		TestTree->cur = TestTree->list_head;
		TestTree->cur_inlist = TestTree->list_head;
		int skip = 0;
		if (layers_amount == 1) {

			readarr = TestTree->get_data();
			to_print[0][0] = readarr[0][0]; to_print[0][1] = readarr[0][1]; to_print[0][2] = 1;
			to_print[1][0] = readarr[1][0]; to_print[1][1] = readarr[1][1]; to_print[1][2] = 1;
			to_print[2][0] = readarr[2][0]; to_print[2][1] = readarr[2][1]; to_print[2][2] = 1;
			to_print[3][0] = readarr[3][0]; to_print[3][1] = readarr[3][1]; to_print[3][2] = 1;
		}else {
			int dir = 0, fX = 0, fY = 0, L = 0;
			if (layers_amount == 2) {
				skip = 0;
				TestTree->go_to_elem_in_list(skip+1);
				TestTree->cur = TestTree->cur_inlist;
				
				for (int i = 0; i < 3; i++) {
					readarr = TestTree->get_data();
					dir = Type_first_to_second(readarr[0][0], readarr[0][1], readarr[6][0], readarr[6][1]);
					
					if (dir == 1) {
						L = (readarr[0][0] - readarr[6][0]) / 2;
						fX = readarr[6][0] - L; fY = readarr[0][1];
					}else {
						if (dir == 2) {
							L = (readarr[6][1] - readarr[0][1]) / 2;
							fX = readarr[6][0]; fY = readarr[6][1] + L;
						}else {
							if (dir == 3) {
								L = (readarr[6][0] - readarr[0][0]) / 2;
								fX = readarr[6][0] + L; fY = readarr[6][1];
							}else {
								if (dir == 4) {
									L = (readarr[0][1] - readarr[6][1]) / 2; 
									fX = readarr[6][0]; fY = readarr[6][1] - L;
								}
							}
						}
					}
					//
					to_print[0 + skip][0] = readarr[0][0]; to_print[0 + skip][1] = readarr[0][1]; to_print[0 + skip][2] = readarr[0][2]; 
					to_print[1 + skip][0] = readarr[1][0]; to_print[1 + skip][1] = readarr[1][1]; to_print[1 + skip][2] = readarr[1][2];
					to_print[2 + skip][0] = readarr[2][0]; to_print[2 + skip][1] = readarr[2][1]; to_print[2 + skip][2] = readarr[2][2];
					to_print[3 + skip][0] = readarr[3][0]; to_print[3 + skip][1] = readarr[3][1]; to_print[3 + skip][2] = readarr[3][2];
					to_print[4 + skip][0] = readarr[4][0]; to_print[4 + skip][1] = readarr[4][1]; to_print[4 + skip][2] = readarr[4][2];
					to_print[5 + skip][0] = readarr[5][0]; to_print[5 + skip][1] = readarr[5][1]; to_print[5 + skip][2] = readarr[5][2];
					to_print[6 + skip][0] = readarr[6][0]; to_print[6 + skip][1] = readarr[6][1]; to_print[6 + skip][2] = readarr[6][2];
					to_print[7 + skip][0] = fX; to_print[7 + skip][1] = fY; to_print[7 + skip][2] = readarr[0][2];
					TestTree->cur = TestTree->cur->next_inlist;
					skip += 8;
				}
				readarr = TestTree->get_data();
				//find dir
				dir = Type_first_to_second(readarr[0][0], readarr[0][1], readarr[6][0], readarr[6][1]);
				if (dir == 1) {
					L = (readarr[0][0] - readarr[6][0]) / 2;
					fX = readarr[6][0] - L; fY = readarr[0][1];
				}else {
					if (dir == 2) {
						L = (readarr[6][1] - readarr[0][1]) / 2;
						fX = readarr[6][0]; fY = readarr[6][1] + L;
					}else {
						if (dir == 3) {
							L = (readarr[6][0] - readarr[0][0]) / 2;
							fX = readarr[6][0] + L; fY = readarr[6][1];
						}else {
							if (dir == 4) {
								L = (readarr[0][1] - readarr[6][1]) / 2; 
								fX = readarr[6][0]; fY = readarr[6][1] - L;
							}
						}
					}
				}
				//
				to_print[0 + skip][0] = readarr[0][0]; to_print[0 + skip][1] = readarr[0][1]; to_print[0 + skip][2] = readarr[0][2];
				to_print[1 + skip][0] = readarr[1][0]; to_print[1 + skip][1] = readarr[1][1]; to_print[1 + skip][2] = readarr[1][2];
				to_print[2 + skip][0] = readarr[2][0]; to_print[2 + skip][1] = readarr[2][1]; to_print[2 + skip][2] = readarr[2][2];
				to_print[3 + skip][0] = readarr[3][0]; to_print[3 + skip][1] = readarr[3][1]; to_print[3 + skip][2] = readarr[3][2];
				to_print[4 + skip][0] = readarr[4][0]; to_print[4 + skip][1] = readarr[4][1]; to_print[4 + skip][2] = readarr[4][2];
				to_print[5 + skip][0] = readarr[5][0]; to_print[5 + skip][1] = readarr[5][1]; to_print[5 + skip][2] = readarr[5][2];
				to_print[6 + skip][0] = readarr[6][0]; to_print[6 + skip][1] = readarr[6][1]; to_print[6 + skip][2] = readarr[6][2];
				to_print[7 + skip][0] = fX; to_print[7 + skip][1] = fY; to_print[7 + skip][2] = readarr[0][2];
				cout << to_print[0][0] << '\n';
			}else {
				if (layers_amount >= 3) {
					skip = 5;
					int skip_c = 0;
					int kh = 0;
					if (layers_amount > 3) {
						kh = 4;
						for (int i = 0; i < layers_amount - 3; i++) {
							kh *= 8;
						}
					}
					skip += kh;
					TestTree->go_to_elem_in_list(skip);
					TestTree->cur = TestTree->cur_inlist;
					int repeat = coor_amount / 8; 
					for (int m = 0; m < repeat - 1; m++) {
						readarr = TestTree->get_data();
						dir = Type_first_to_second(readarr[0][0], readarr[0][1], readarr[6][0], readarr[6][1]);

						if (dir == 1) {
							L = (readarr[0][0] - readarr[6][0]) / 2;
							fX = readarr[6][0] - L; fY = readarr[0][1];
						}
						else {
							if (dir == 2) {
								L = (readarr[6][1] - readarr[0][1]) / 2;
								fX = readarr[6][0]; fY = readarr[6][1] + L;
							}
							else {
								if (dir == 3) {
									L = (readarr[6][0] - readarr[0][0]) / 2;
									fX = readarr[6][0] + L; fY = readarr[6][1];
								}
								else {
									if (dir == 4) {
										L = (readarr[0][1] - readarr[6][1]) / 2;
										fX = readarr[6][0]; fY = readarr[6][1] - L;
									}
								}
							}
						}
						//
						to_print[0 + skip_c][0] = readarr[0][0]; to_print[0 + skip_c][1] = readarr[0][1]; to_print[0 + skip_c][2] = readarr[0][2];
						to_print[1 + skip_c][0] = readarr[1][0]; to_print[1 + skip_c][1] = readarr[1][1]; to_print[1 + skip_c][2] = readarr[1][2];
						to_print[2 + skip_c][0] = readarr[2][0]; to_print[2 + skip_c][1] = readarr[2][1]; to_print[2 + skip_c][2] = readarr[2][2];
						to_print[3 + skip_c][0] = readarr[3][0]; to_print[3 + skip_c][1] = readarr[3][1]; to_print[3 + skip_c][2] = readarr[3][2];
						to_print[4 + skip_c][0] = readarr[4][0]; to_print[4 + skip_c][1] = readarr[4][1]; to_print[4 + skip_c][2] = readarr[4][2];
						to_print[5 + skip_c][0] = readarr[5][0]; to_print[5 + skip_c][1] = readarr[5][1]; to_print[5 + skip_c][2] = readarr[5][2];
						to_print[6 + skip_c][0] = readarr[6][0]; to_print[6 + skip_c][1] = readarr[6][1]; to_print[6 + skip_c][2] = readarr[6][2];
						to_print[7 + skip_c][0] = fX; to_print[7 + skip_c][1] = fY; to_print[7 + skip_c][2] = readarr[0][2];
						TestTree->cur = TestTree->cur->next_inlist;
						skip_c += 8;
					}

					readarr = TestTree->get_data();
					dir = Type_first_to_second(readarr[0][0], readarr[0][1], readarr[6][0], readarr[6][1]);

					if (dir == 1) {
						L = (readarr[0][0] - readarr[6][0]) / 2;
						fX = readarr[6][0] - L; fY = readarr[0][1];
					}
					else {
						if (dir == 2) {
							L = (readarr[6][1] - readarr[0][1]) / 2;
							fX = readarr[6][0]; fY = readarr[6][1] + L;
						}
						else {
							if (dir == 3) {
								L = (readarr[6][0] - readarr[0][0]) / 2;
								fX = readarr[6][0] + L; fY = readarr[6][1];
							}
							else {
								if (dir == 4) {
									L = (readarr[0][1] - readarr[6][1]) / 2;
									fX = readarr[6][0]; fY = readarr[6][1] - L;
								}
							}
						}
					}
					//
					to_print[0 + skip_c][0] = readarr[0][0]; to_print[0 + skip_c][1] = readarr[0][1]; to_print[0 + skip_c][2] = readarr[0][2];
					to_print[1 + skip_c][0] = readarr[1][0]; to_print[1 + skip_c][1] = readarr[1][1]; to_print[1 + skip_c][2] = readarr[1][2];
					to_print[2 + skip_c][0] = readarr[2][0]; to_print[2 + skip_c][1] = readarr[2][1]; to_print[2 + skip_c][2] = readarr[2][2];
					to_print[3 + skip_c][0] = readarr[3][0]; to_print[3 + skip_c][1] = readarr[3][1]; to_print[3 + skip_c][2] = readarr[3][2];
					to_print[4 + skip_c][0] = readarr[4][0]; to_print[4 + skip_c][1] = readarr[4][1]; to_print[4 + skip_c][2] = readarr[4][2];
					to_print[5 + skip_c][0] = readarr[5][0]; to_print[5 + skip_c][1] = readarr[5][1]; to_print[5 + skip_c][2] = readarr[5][2];
					to_print[6 + skip_c][0] = readarr[6][0]; to_print[6 + skip_c][1] = readarr[6][1]; to_print[6 + skip_c][2] = readarr[6][2];
					to_print[7 + skip_c][0] = fX; to_print[7 + skip_c][1] = fY; to_print[7 + skip_c][2] = readarr[0][2];

				}
			}
			
		}
		
		int number = 1;
		TestTree->cur = TestTree->list_head;
		TestTree->cur_inlist = TestTree->list_head;
		while (TestTree->cur != nullptr) {
			readarr = TestTree->get_data();
			cout << "N: " << number << " " << "( " << readarr[0][0] << ", " << readarr[0][1] << ", col = "<< readarr[0][2]<<" ), " << "(" << readarr[1][0] << ", " << readarr[1][1] << ", col = " << readarr[1][2] << "), " << "(" << readarr[2][0] << ", " << readarr[2][1] << ", col = " << readarr[2][2] << "), " << "(" << readarr[3][0] << ", " << readarr[3][1] << ", col = " << readarr[3][2] << "), " << "(" << readarr[4][0] << ", " << readarr[4][1] << ", col = " << readarr[4][2] << "), " << "(" << readarr[5][0] << ", " << readarr[5][1] << ", col = " << readarr[5][2] << "), " << "(" << readarr[6][0] << ", " << readarr[6][1] << ", col = " << readarr[6][2] << "), " << '\n';
			number++;
			TestTree->cur = TestTree->cur->next_inlist;
		}
		
		
		
	}
	return to_print;
}
//

int** TREE_DATA_FORM(int x0, int y0, int layers_amount, int col_amount) {
	if (layers_amount < 1) {
		layers_amount = 1;
	}
	int color_count = 1;
	int cube_l = 4;
	for (int i = 0; i < layers_amount - 1; i++) {
		cube_l *= 4;
	}//задание размеров куба
	const int size_one = 7;
	const int size_two = 3;
	FRactTree<int**>* TestTree = new FRactTree<int**>();
	int** arr = new int* [size_one];
	for (int count = 0; count < size_one; count++) {
		arr[count] = new int[size_two];
	}
	TestTree->SetTreeList(layers_amount, arr);
	int coor_amount = 0;
	if (layers_amount == 1) {
		coor_amount = 4;
	}
	else {
		if (layers_amount == 2) {
			coor_amount = 4;
		}
		else {
			if (layers_amount >= 3) {
				coor_amount = 4;
				for (int k = 0; k < layers_amount - 2; k++) {
					coor_amount *= 8;
				}
			}
		}
		coor_amount = coor_amount * 8;
	}

	int** to_print = new int* [coor_amount];
	cout << coor_amount << '\n';
	for (int i = 0; i < coor_amount; i++) {
		to_print[i] = new int[3];
	}
	for (int i = 0; i < coor_amount; i++) {
		for (int j = 0; j < 3; j++) {
			to_print[i][j] = -10000;
		}
	}


	//TestTree->SetConnections();
	//задание дерева
	if (layers_amount >= 1) {
		int A1x, A2x, A3x, A4x, A1y, A2y, A3y, A4y;
		A1x = x0 + cube_l / 2; A1y = y0 - cube_l / 2;
		A2x = x0 - cube_l / 2; A2y = y0 - cube_l / 2;
		A3x = x0 - cube_l / 2; A3y = y0 + cube_l / 2;
		A4x = x0 + cube_l / 2; A4y = y0 + cube_l / 2;
		//
		arr = new int* [size_one];
		for (int count = 0; count < size_one; count++) {
			arr[count] = new int[size_two];
		}
		//реинициализация массива координат
		arr[0][0] = A1x; arr[0][1] = A1y; arr[0][2] = color_count;
		arr[1][0] = A2x; arr[1][1] = A2y; arr[1][2] = color_count;
		arr[2][0] = A3x; arr[2][1] = A3y; arr[2][2] = color_count;
		arr[3][0] = A4x; arr[3][1] = A4y; arr[3][2] = color_count;

		arr[4][0] = 1000; arr[4][1] = 1000; arr[4][2] = color_count;
		arr[5][0] = 1000; arr[5][1] = 1000; arr[5][2] = color_count;
		arr[6][0] = 1000; arr[6][1] = 1000; arr[6][2] = color_count;
		TestTree->cur = TestTree->list_head;
		TestTree->cur_inlist = TestTree->list_head;
		TestTree->set_data(arr);
		if (layers_amount >= 2) {
			int** getarr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				getarr[count] = new int[size_two];
			}
			TestTree->cur = TestTree->list_head;
			getarr = TestTree->get_data();
			int direction = 0;
			int dx1, dx2, dx3, dx4, dx5, dx6, dx7, dy1, dy2, dy3, dy4, dy5, dy6, dy7;
			int col_f, col_rest;
			col_f = getarr[0][2]; col_rest = getarr[0][2] + 1;
			//dir=1
			int X1 = getarr[0][0]; int Y1 = getarr[0][1];
			int X2 = getarr[1][0]; int Y2 = getarr[1][1];
			int L = X1 - X2;
			dx1 = X1 - (L / 4); dx2 = dx1;
			dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
			dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
			dy1 = Y2; dy4 = dy1; dy7 = dy1;
			dy2 = Y2 + (L / 4); dy3 = dy2;
			dy5 = Y2 - (L / 4); dy6 = dy5;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1;
			arr[1][0] = dx2; arr[1][1] = dy2;
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5;
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			//dir=2
			X1 = getarr[1][0]; Y1 = getarr[1][1];
			X2 = getarr[2][0]; Y2 = getarr[2][1];
			L = Y2 - Y1;
			dx5 = X1 - (L / 4); dx6 = dx5;
			dx1 = X1; dx4 = dx1; dx7 = dx1;
			dx2 = X1 + (L / 4); dx3 = dx2;
			dy1 = Y1 + (L / 4); dy2 = dy1;
			dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
			dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1;
			arr[1][0] = dx2; arr[1][1] = dy2;
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5;
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			//dir=3

			X1 = getarr[2][0]; Y1 = getarr[2][1];
			X2 = getarr[3][0]; Y2 = getarr[3][1];
			L = X2 - X1;
			dx1 = X1 + L / 4; dx2 = dx1;
			dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
			dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
			dy1 = Y1; dy4 = dy1; dy7 = dy1;
			dy2 = Y1 - L / 4; dy3 = dy2;
			dy5 = Y1 + L / 4; dy6 = dy5;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1;
			arr[1][0] = dx2; arr[1][1] = dy2;
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5;
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			//dir=4

			X1 = getarr[3][0]; Y1 = getarr[3][1];
			X2 = getarr[0][0]; Y2 = getarr[0][1];
			L = Y1 - Y2;
			dx5 = X2 + L / 4; dx6 = dx5;
			dx1 = X2; dx4 = dx1; dx7 = dx1;
			dx2 = X2 - L / 4; dx3 = dx2;
			dy1 = Y1 - L / 4; dy2 = dy1;
			dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
			dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
			//
			arr = new int* [size_one];
			for (int count = 0; count < size_one; count++) {
				arr[count] = new int[size_two];
			}
			//реинициализация массива координат
			arr[0][0] = dx1; arr[0][1] = dy1;
			arr[1][0] = dx2; arr[1][1] = dy2;
			arr[2][0] = dx3; arr[2][1] = dy3;
			arr[3][0] = dx4; arr[3][1] = dy4;
			arr[4][0] = dx5; arr[4][1] = dy5;
			arr[5][0] = dx6; arr[5][1] = dy6;
			arr[6][0] = dx7; arr[6][1] = dy7;

			arr[0][2] = col_f;
			arr[1][2] = col_rest;
			arr[2][2] = col_rest;
			arr[3][2] = col_rest;
			arr[4][2] = col_rest;
			arr[5][2] = col_rest;
			arr[6][2] = col_rest;
			TestTree->cur = TestTree->cur->next_inlist;
			TestTree->set_data(arr);
			if (layers_amount >= 3) {
				int skip_to_parent = 1;
				int parent_amount = 4;
				int skip_to_desc = skip_to_parent + parent_amount;
				int col_fase = 3;
				for (int g = 0; g < layers_amount - 2; g++) {

					for (int i = 0; i < parent_amount; i++) {
						TestTree->set_auxl_pos(i + skip_to_parent);
						TestTree->cur = TestTree->auxl_pos;
						getarr = TestTree->get_data();
						col_f = getarr[0][2];
						col_rest = getarr[1][2];
						int dir18;
						int dir;
						dir18 = Type_first_to_second(getarr[0][0], getarr[0][1], getarr[6][0], getarr[6][1]);
						int Stx = 0, Sty = 0, Etx = 0, Ety = 0;
						if (dir18 == 1) {
							L = (getarr[0][0] - getarr[6][0]) / 2;
							Stx = getarr[0][0] + L; Sty = getarr[0][1];
							Etx = getarr[6][0] - L; Ety = Sty;

						}
						else {
							if (dir18 == 2) {
								L = (getarr[6][1] - getarr[0][1]) / 2;
								Stx = getarr[0][0]; Sty = getarr[0][1] - L;
								Etx = Stx; Ety = getarr[6][1] + L;

							}
							else {
								if (dir18 == 3) {
									L = (getarr[6][0] - getarr[0][0]) / 2;
									Stx = getarr[0][0] - L; Sty = getarr[0][1];
									Etx = getarr[6][0] + L; Ety = Sty;

								}
								else {
									if (dir18 == 4) {
										L = (getarr[0][1] - getarr[6][1]) / 2;
										Stx = getarr[0][0]; Sty = getarr[0][1] + L;
										Etx = Stx; Ety = getarr[6][1] - L;

									}
								}
							}
						}

						//1
						TestTree->go_to_elem_in_list(skip_to_desc);
						TestTree->cur = TestTree->cur_inlist;
						X1 = Stx; Y1 = Sty; X2 = getarr[0][0]; Y2 = getarr[0][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 - (L / 4); dy3 = dy2;
							dy5 = Y2 + (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_f;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_f;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_f;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_f;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//2
						TestTree->go_to_elem_in_list(skip_to_desc + 1);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[0][0]; Y1 = getarr[0][1]; X2 = getarr[1][0]; Y2 = getarr[1][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//3
						TestTree->go_to_elem_in_list(skip_to_desc + 2);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[1][0]; Y1 = getarr[1][1]; X2 = getarr[2][0]; Y2 = getarr[2][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//4
						TestTree->go_to_elem_in_list(skip_to_desc + 3);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[2][0]; Y1 = getarr[2][1]; X2 = getarr[3][0]; Y2 = getarr[3][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//5
						TestTree->go_to_elem_in_list(skip_to_desc + 4);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[3][0]; Y1 = getarr[3][1]; X2 = getarr[4][0]; Y2 = getarr[4][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//6
						TestTree->go_to_elem_in_list(skip_to_desc + 5);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[4][0]; Y1 = getarr[4][1]; X2 = getarr[5][0]; Y2 = getarr[5][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//7
						TestTree->go_to_elem_in_list(skip_to_desc + 6);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[5][0]; Y1 = getarr[5][1]; X2 = getarr[6][0]; Y2 = getarr[6][1];
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_rest;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_rest;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_rest;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_rest;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//8
						TestTree->go_to_elem_in_list(skip_to_desc + 7);
						TestTree->cur = TestTree->cur_inlist;
						X1 = getarr[6][0]; Y1 = getarr[6][1]; X2 = Etx; Y2 = Ety;
						dir = Type_first_to_second(X1, Y1, X2, Y2);
						if (dir == 1) {

							L = X1 - X2;
							dx1 = X1 - (L / 4); dx2 = dx1;
							dx3 = X1 - (L / 2); dx4 = dx3; dx5 = dx3;
							dx6 = X1 - ((L * 3) / 4); dx7 = dx6;
							dy1 = Y2; dy4 = dy1; dy7 = dy1;
							dy2 = Y2 + (L / 4); dy3 = dy2;
							dy5 = Y2 - (L / 4); dy6 = dy5;
							//
							arr = new int* [size_one];
							for (int count = 0; count < size_one; count++) {
								arr[count] = new int[size_two];
							}
							//реинициализация массива координат
							arr[0][0] = dx1; arr[0][1] = dy1;
							arr[1][0] = dx2; arr[1][1] = dy2;
							arr[2][0] = dx3; arr[2][1] = dy3;
							arr[3][0] = dx4; arr[3][1] = dy4;
							arr[4][0] = dx5; arr[4][1] = dy5;
							arr[5][0] = dx6; arr[5][1] = dy6;
							arr[6][0] = dx7; arr[6][1] = dy7;

							arr[0][2] = col_f;
							arr[1][2] = col_fase;
							arr[2][2] = col_fase;
							arr[3][2] = col_fase;
							arr[4][2] = col_fase;
							arr[5][2] = col_fase;
							arr[6][2] = col_fase;
							TestTree->set_data(arr);
						}
						else {
							if (dir == 2) {
								L = Y2 - Y1;
								dx5 = X1 - (L / 4); dx6 = dx5;
								dx1 = X1; dx4 = dx1; dx7 = dx1;
								dx2 = X1 + (L / 4); dx3 = dx2;
								dy1 = Y1 + (L / 4); dy2 = dy1;
								dy3 = Y1 + (L / 2); dy4 = dy3; dy5 = dy3;
								dy6 = Y1 + ((L * 3) / 4); dy7 = dy6;
								//
								arr = new int* [size_one];
								for (int count = 0; count < size_one; count++) {
									arr[count] = new int[size_two];
								}
								//реинициализация массива координат
								arr[0][0] = dx1; arr[0][1] = dy1;
								arr[1][0] = dx2; arr[1][1] = dy2;
								arr[2][0] = dx3; arr[2][1] = dy3;
								arr[3][0] = dx4; arr[3][1] = dy4;
								arr[4][0] = dx5; arr[4][1] = dy5;
								arr[5][0] = dx6; arr[5][1] = dy6;
								arr[6][0] = dx7; arr[6][1] = dy7;

								arr[0][2] = col_f;
								arr[1][2] = col_fase;
								arr[2][2] = col_fase;
								arr[3][2] = col_fase;
								arr[4][2] = col_fase;
								arr[5][2] = col_fase;
								arr[6][2] = col_fase;
								TestTree->set_data(arr);
							}
							else {
								if (dir == 3) {
									L = X2 - X1;
									dx1 = X1 + L / 4; dx2 = dx1;
									dx3 = X1 + L / 2; dx4 = dx3; dx5 = dx3;
									dx6 = X1 + ((L * 3) / 4); dx7 = dx6;
									dy1 = Y1; dy4 = dy1; dy7 = dy1;
									dy2 = Y1 - L / 4; dy3 = dy2;
									dy5 = Y1 + L / 4; dy6 = dy5;
									//
									arr = new int* [size_one];
									for (int count = 0; count < size_one; count++) {
										arr[count] = new int[size_two];
									}
									//реинициализация массива координат
									arr[0][0] = dx1; arr[0][1] = dy1;
									arr[1][0] = dx2; arr[1][1] = dy2;
									arr[2][0] = dx3; arr[2][1] = dy3;
									arr[3][0] = dx4; arr[3][1] = dy4;
									arr[4][0] = dx5; arr[4][1] = dy5;
									arr[5][0] = dx6; arr[5][1] = dy6;
									arr[6][0] = dx7; arr[6][1] = dy7;

									arr[0][2] = col_f;
									arr[1][2] = col_fase;
									arr[2][2] = col_fase;
									arr[3][2] = col_fase;
									arr[4][2] = col_fase;
									arr[5][2] = col_fase;
									arr[6][2] = col_fase;
									TestTree->set_data(arr);
								}
								else {
									if (dir == 4) {
										L = Y1 - Y2;
										dx5 = X2 + L / 4; dx6 = dx5;
										dx1 = X2; dx4 = dx1; dx7 = dx1;
										dx2 = X2 - L / 4; dx3 = dx2;
										dy1 = Y1 - L / 4; dy2 = dy1;
										dy3 = Y1 - L / 2; dy4 = dy3; dy5 = dy3;
										dy6 = Y1 - ((L * 3) / 4); dy7 = dy6;
										//
										arr = new int* [size_one];
										for (int count = 0; count < size_one; count++) {
											arr[count] = new int[size_two];
										}
										//реинициализация массива координат
										arr[0][0] = dx1; arr[0][1] = dy1;
										arr[1][0] = dx2; arr[1][1] = dy2;
										arr[2][0] = dx3; arr[2][1] = dy3;
										arr[3][0] = dx4; arr[3][1] = dy4;
										arr[4][0] = dx5; arr[4][1] = dy5;
										arr[5][0] = dx6; arr[5][1] = dy6;
										arr[6][0] = dx7; arr[6][1] = dy7;

										arr[0][2] = col_f;
										arr[1][2] = col_fase;
										arr[2][2] = col_fase;
										arr[3][2] = col_fase;
										arr[4][2] = col_fase;
										arr[5][2] = col_fase;
										arr[6][2] = col_fase;
										TestTree->set_data(arr);
									}
								}
							}
						}
						//
						skip_to_desc += 8;
					}
					col_fase++;
					skip_to_parent = skip_to_parent + parent_amount;
					parent_amount = parent_amount * 8;
					//skip_to_desc = skip_to_parent + parent_amount;
				}


			}

		}
	}
}
int main() {
	//TEST();

	int layers_amount = 3;

	int**  to_print = COOR_COUNT(100, 100, layers_amount,4);
	int coor_amount = 0;
	if (layers_amount == 1) {
		coor_amount = 4;
	}
	else {
		if (layers_amount == 2) {
			coor_amount = 4;
		}
		else {
			if (layers_amount >= 3) {
				coor_amount = 4;
				for (int k = 0; k < layers_amount - 2; k++) {
					coor_amount *= 8;
				}
			}
		}
		coor_amount = coor_amount * 8;
	}
	for (int i = 0; i < coor_amount; i++) {
		cout <<"N: "<<i+1 << "(" << to_print[i][0] << ", " << to_print[i][1] << ") col = " << to_print[i][2] << '\n';
	}
	return 0;
}