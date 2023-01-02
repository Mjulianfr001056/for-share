#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//_id digunakan untuk membuat primary key setiap kontak dalam contact book
static int _id = 1;
//Bagian Single Linked List untuk menyimpan kontak

//Membuat setiap node dari linked list (dimaksudkan untuk menyimpan kontaknya)
typedef struct node Tnode;
struct node{
	int _id;
	char nama[20];
    unsigned umur;
    bool jenis_kelamin; // 1 untuk laki-laki, 0 untuk perempuan (lebih hemat memori)
    char no_telp[15];
    char email[20];
	Tnode* next;
};
typedef Tnode* ptrnode;

//Membuat Linked List (Linked list dibungkus dalam suatu struct lagi)
typedef struct SinglyLinkedList SLL;
struct SinglyLinkedList{
	ptrnode head;
	unsigned size; //Dibungkus supaya tau besarnya linked list itu berapa
};
typedef SLL* ptrSLL;

//Implementasi node relasi Kontak (dimaksudkan untuk menyimpan relasi sehingga dinamis ke kanan)
typedef struct node_1D Tnode_1D;
struct node_1D{
	int data;
	Tnode_1D* next;
};
typedef Tnode_1D* ptrnode_1D;

//Bungkus linkedlist yang ke dinamis ke samping
typedef struct SinglyLinkedList_1D SLL_1D;
struct SinglyLinkedList_1D{
	ptrnode_1D head;
	int size;
};
typedef SLL_1D* ptrSLL_1D;

//Implementasi node adjacency List
//node dari adjacency list adalah sebuah pointer ke sebuah linkedlist 1D 
typedef struct adjacencyListNode adjListNode;
struct adjacencyListNode{
	ptrSLL_1D data_list;
	adjListNode* next;
};
typedef adjListNode* ptrAdjListNode;

//Bungkus AdjacencyList lagi supaya tau size nya wkwk
typedef struct adjacencyList adjList;
struct adjacencyList{
	ptrAdjListNode head;
	int size;
};
typedef adjList* ptrAdjList;

//Implementasi item dalam hash table (digunakan untuk pemetaan cepat primary key ID ke pointer yang menunjuk ke kontak nya)
typedef struct item Titem;
struct item{
	int key;
	ptrnode data;
	Titem* next;
};
typedef Titem* ptritem;

//Bungkus lagi hashtable nya agar lebih rapi juga :D
typedef struct hash_table HashTable;
struct hash_table{
	ptritem head;
	int capacity;
};
typedef HashTable* ptrHashTable;

//List subprogram yang berhubungan dengan linkedlist yang menyimpan kontak

//subprogram untuk node nya
ptrnode createNode(char pNama[], unsigned pUmur, bool pJenis_kelamin, char pNo_telp[], char pEmail[]); //Membuat node kontak
void printNode(ptrnode tmp); //Mencetak suatu kontak 

//Subprogram untuk linkedlist-nya
void SLL_init(ptrSLL tmpList); //Inisialisasi struct untuk ngebungkus Single Linked List
void SLL_insert(ptrSLL currList, ptrnode currNode, ptrAdjList currAdjList, ptrHashTable currHashTable); //Insert kontak ke SLL
void SLL_popFront(ptrSLL currList); //Menghapus head linked list
void SLL_popBack(ptrSLL currList); //Menghapus tail linked list
void SLL_deleteNama(ptrSLL currList, char nama[]); //Menghapus suatu kontak berdasarkan nama

//List subprogram yang berhubungan dengan linkedlist yang menyimpan relasi ke samping
/*
	Perbedaan SLL dengan SLL_1D

	SLL->digunakan untuk menyimpan kontak karena dia merupakan linked list of struct kontak
	SLL->linkedlist menyimpan nama, umur, jenis kelamin, dll

	SLL_1D->digunakan untk menyimpan relasi, merupakan row dari suatu adjacency list
	SLL_1D->linkedlist hanya menyimpan id saja
*/

//subprogram untuk node nya
ptrnode_1D createNode_1D(int Pnum); //Membuat node relasi

//Subprogram untuk linkedlist-nya
void SLL_1D_init(ptrSLL_1D tmpList); //Inisialisasi struct untuk ngebungkus Single Linked List 1D
void SLL_1D_pushBack(ptrSLL_1D currList, int data); //Untuk meng-insert tail ke SLL 1D
void SLL_1D_popFront(ptrSLL_1D currList); //Untuk meng-delete head dari SLL 1D
void SLL_1D_popBack(ptrSLL_1D currList); //Untuk meng-delete tail dari SLL 1D
void SLL_1D_deleteNode(ptrSLL_1D currList, int idName); //Untuk menghapus suatu node berdasarkan ID nya

//List subprogram yang berhubungan dengan linkedlist yang menyimpan relasi ke atas
//linkedlist ini 2D, di sini disebut sbg adjacency list

//subprogram untuk node nya (row)
void adjListNode_init(ptrAdjListNode currAdjListNode); //Inisialisasi row
ptrAdjListNode createNode_adj(int src); //Membuat subuah row, src adalah nama row tsb

//Subprogram untuk Adjlist nya (2D linkedlist)
void adjList_init(ptrAdjList currAdjList); //inisiasi adjlist
void adjList_pushBack(ptrAdjList currAdjList, int src);//Membuat insert relasi di baris ke sekian
void adjList_insertRelation(ptrAdjList currAdjList, int src, int fin); //insert tail (fin) pada baris ke (src) / artinya src dan fin berelasi
void adjList_deleteRelation(ptrAdjList currAdjList, int src, int fin); //hapus (fin) pada baris ke (src)

//List subprogram yang berhubungan dengan hashTable

//Subprogram untuk item nya
ptritem createItem(int Pkey, ptrnode Pnode); //Membuat item

//Subprogram untuk Hash Table nya
void hashTable_init(ptrHashTable currHashTable); //Inisiasi hash table
void hashTable_pushBack(ptrHashTable currHashTable, int key, ptrnode currnode); //insert tail indexing baru ke hash table
ptrnode hashTable_getData(ptrHashTable currHashTable, int Pkey); //mengambil pointer ke kontak dengan id

//Fungsi yang dipakai di program utama
void menu1(ptrSLL daftarKontak);
void menu2(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu3(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu4(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu5(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID);
void menu6(ptrSLL daftarKontak, ptrHashTable indeksID);
void menu7(ptrSLL daftarKontak);
void menu8(ptrAdjList daftarRelasi, ptrHashTable indeksID);

//Subprogram sampingan untuk menunjang program

//bagian dari mergesort berdasarkan nama
ptrnode merge(ptrnode firstNode, ptrnode secondNode);
ptrnode mid_SLL(ptrnode head);
ptrnode sortNama(ptrnode daftarKontak);

//bagian dari binarysearch berdasarkan nama
ptrnode middle(ptrnode start, ptrnode last);
ptrnode cariBinarySearch_nama(ptrSLL daftarKontak, char nama[]);

//bagian lainnya
int cariID(ptrSLL daftarKontak, char nama[]); //Mencari ID dari nama kontak
void editProp(ptrSLL daftarKontak, int flag, int _id, ptrHashTable indeksID); //Bantuan buat edit property aja sih

int main(){
	//inisiasi daftar kontak
    ptrSLL daftarKontak = (ptrSLL) malloc(sizeof(SLL));;
    SLL_init(daftarKontak);
	
	//inisiasi daftar relasi
	ptrAdjList daftarRelasi = (ptrAdjList) malloc(sizeof(adjList));
	adjList_init(daftarRelasi);

	//inisisasi indexing
	ptrHashTable indeksID = (ptrHashTable) malloc(sizeof(HashTable));
	hashTable_init(indeksID);

	//Ceritanya kontak yang sudah ada saat ini
    SLL_insert(daftarKontak, createNode("Julian Firdaus", 17, true, "08127898xxxx", "julian@gmail.com"), daftarRelasi, indeksID);
    SLL_insert(daftarKontak, createNode("Dutatama R", 19, true, "08580250xxxx", "dutata@gmail.com"), daftarRelasi, indeksID);
    SLL_insert(daftarKontak, createNode("Sariyyanti P", 20, false, "08778877xxxx", "sariyy@gmail.com"), daftarRelasi, indeksID);
    SLL_insert(daftarKontak, createNode("Ainul B", 19, true, "08112193xxxx", "ainul@gmail.com"), daftarRelasi, indeksID);

	//Ceritanya relasi yang udah diketahui saat ini
	adjList_insertRelation(daftarRelasi, 1, 4);
	adjList_insertRelation(daftarRelasi, 2, 3);
	adjList_insertRelation(daftarRelasi, 2, 4);
	adjList_insertRelation(daftarRelasi, 3, 4);
	
	bool isFinished = false;
	int _menu = 0;

	daftarKontak->head = sortNama(daftarKontak->head);
	do{
		printf("===========================================\n");
		printf("=               Buku Kontak               =\n");
		printf("===========================================\n");

		printf("Menu: \n");
		printf("1. Cari Kontak\n");
		printf("2. Tambah Kontak\n");
		printf("3. Tambah Relasi\n");
		printf("4. Hapus Kontak\n");
		printf("5. Hapus Relasi\n");
		printf("6. Sunting Kontak\n");
		printf("7. Tampilkan Kontak\n");
		printf("8. Tampilkan Relasi\n");
		printf("9. Keluar\n");
		printf("Masukkan menu: ");

		scanf("%d", &_menu);

		system("cls");
		switch (_menu){
		case 1:
			menu1(daftarKontak);
			break;
		case 2:
			menu2(daftarKontak, daftarRelasi, indeksID);
			break;
		case 3:
			menu3(daftarKontak, daftarRelasi, indeksID);
			break;
		case 4:
			menu4(daftarKontak, daftarRelasi, indeksID);
			break;
		case 5:
			menu5(daftarKontak, daftarRelasi, indeksID);
			break;
		case 6:
			menu6(daftarKontak, indeksID);
			break;
		case 7:
			menu7(daftarKontak);
			break;
		case 8:
			menu8(daftarRelasi, indeksID);
			break;
		case 9:
			isFinished = true;
			printf("Anda keluar...\n");
			break;
		default:
			system("cls");
			printf("Masukan salah!\n\n");		
		}
	}while(!isFinished);
}

void menu1(ptrSLL daftarKontak){
	char nama[20];

	printf("===========================================\n");
	printf("=               Cari Kontak               =\n");
	printf("===========================================\n");

	printf("Masukkan nama: ");

	getchar();
	gets(nama);
	
	daftarKontak->head = sortNama(daftarKontak->head);
	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);

	system("cls");

	printf("===========================================\n");
	printf("=                  Hasil                  =\n");
	printf("===========================================\n");

	(tmp != NULL) ? printNode(tmp) : printf("Data tidak ditemukan!\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu2(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char nama[20];
    unsigned umur;
    int jenis_kelamin; // 1 untuk laki-laki, 0 untuk perempuan (lebih hemat memori)
    char no_telp[15];
    char email[20];

	printf("===========================================\n");
	printf("=              Tambah Kontak              =\n");
	printf("===========================================\n");

	printf("%-15s: ", "Nama");
	getchar();
	gets(nama);

	printf("%-15s: ", "Umur");
	scanf("%d", &umur);
	
	printf("%-15s: ", "Jenis Kelamin");
	scanf("%d", &jenis_kelamin);

	printf("%-15s: ", "Nomor Telefon");
	getchar();
	gets(no_telp);

	printf("%-15s: ", "Alamat Email");
	gets(email);

	SLL_insert(daftarKontak, createNode(nama, umur, (bool) jenis_kelamin, no_telp, email), daftarRelasi, indeksID);
	daftarKontak->head = sortNama(daftarKontak->head);

	system("cls");
	printf("Data berhasil ditambahkan!\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu3(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char src[20];
	char fin[20];
	int i = 0, n = 0;

	printf("===========================================\n");
	printf("=              Tambah Relasi              =\n");
	printf("===========================================\n");

	printf("Format input: \n");
	printf("[Nama 1], [Nama 2]\n\n");
	printf("Contoh: \n");
	printf("Ainul B, Julian Firdaus\n\n");

	printf("Banyak relasi yang ingin dimasukkan: ");
	scanf("%d", &n);
	getchar();
	
	for(i = 0; i<n; i++){
		printf("Relasi ke-%d: ", i+1);
		scanf("%19[^,], %19[^\n]", &src, &fin);
		getchar();
		ptrnode id_src = hashTable_getData(indeksID, cariID(daftarKontak, src));
		ptrnode id_fin = hashTable_getData(indeksID, cariID(daftarKontak, fin));

		if(id_src == NULL || id_fin == NULL){
			printf("Relasi gagal ditambahkan, pastikan data yang dimasukkan sudah tersedia!\n");
			i--;
		}else adjList_insertRelation(daftarRelasi, id_src->_id, id_fin->_id);
	}

	system("cls");
	printf("Data berhasil ditambahkan!\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu4(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char nama[20];

	printf("===========================================\n");
	printf("=             Hapus  Kontak               =\n");
	printf("===========================================\n");

	printf("Masukkan nama: ");

	getchar();
	gets(nama);
	
	daftarKontak->head = sortNama(daftarKontak->head);
	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);
	system("cls");

	if(tmp == NULL){
		printf("Data tidak ditemukan, tidak ada yang dihapus!\n");
	}else{
		SLL_deleteNama(daftarKontak, tmp->nama);
		printf("Data Berhasil dihapus!\n");
	}
	printf("===========================================\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu5(ptrSLL daftarKontak, ptrAdjList daftarRelasi, ptrHashTable indeksID){
	char nama[20];
	char nama2[20];
	printf("===========================================\n");
	printf("=             Hapus  Relasi               =\n");
	printf("===========================================\n");

	printf("Masukkan nama orang pertama: ");

	getchar();
	gets(nama);
	
	printf("Masukkan nama orang kedua  : ");

	gets(nama2);

	daftarKontak->head = sortNama(daftarKontak->head);
	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);
	ptrnode tmp2 = cariBinarySearch_nama(daftarKontak, nama2);
	system("cls");

	if(tmp == NULL || tmp2 == NULL){
		printf("Data tidak ditemukan, tidak ada yang dihapus!\n");
	}else{
		int tmp_id = tmp->_id;
		int tmp2_id = tmp2->_id;

		adjList_deleteRelation(daftarRelasi, tmp_id, tmp2_id);
		printf("Data berhasil dihapus!\n");
	}

	printf("===========================================\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu6(ptrSLL daftarKontak, ptrHashTable indeksID){
	char nama[20];
	int _flag = 0;

	printf("===========================================\n");
	printf("=            Sunting Kontak               =\n");
	printf("===========================================\n");

	printf("Masukkan nama: ");

	getchar();
	gets(nama);

	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);

	if(tmp != NULL){
		printf("\nApa yang ingin disunting? \n");
		printf("1. Nama\n");
		printf("2. Umur\n");
		printf("3. Jenis kelamin\n");
		printf("4. Nomor Telefon\n");
		printf("5. Alamat Email\n");
		printf("Masukkan nama: ");

		scanf("%d", &_flag);
		
		editProp(daftarKontak, _flag, tmp->_id, indeksID);	
	}else{
		printf("\nData tidak ditemukan!\n");
	}

	printf("===========================================\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

void menu7(ptrSLL daftarKontak){
	ptrnode tmp = daftarKontak->head;

	printf("===========================================\n");
	printf("=              Tampil Kontak              =\n");
	printf("===========================================\n");
	printf("Jumlah kontak: %d\n", daftarKontak->size);

	while(tmp!=NULL){
		printf("===========================================\n");
		printNode(tmp);
		tmp = tmp->next;
	}

	printf("===========================================\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	getchar();
	system("cls");
}

void menu8(ptrAdjList daftarRelasi, ptrHashTable indeksID){
	printf("===========================================\n");
	printf("=              Tampil Relasi              =\n");
	printf("===========================================\n");
	
	if(daftarRelasi->size == 0){
		printf("Relasi Kosong! \n");
	}else{
		ptrAdjListNode cursor = daftarRelasi->head;
		ptrnode_1D cursor2 = cursor->data_list->head;
		
		while(cursor != NULL){
			printf("%-20s: ", hashTable_getData(indeksID, cursor2->data)->nama);
			cursor2 = cursor2->next;

			while(cursor2 != NULL){
				printf("(%s) ", hashTable_getData(indeksID, cursor2->data)->nama);
				cursor2 = cursor2->next;
			}
			printf("\n");
			cursor = cursor->next;
			if(cursor != NULL) cursor2 = cursor->data_list->head;
		}

		printf("===========================================\n");
		printf("Tekan untuk melanjutkan...");
		getchar();
		getchar();
		system("cls");
	}
}

ptrnode createNode(char pNama[], unsigned pUmur, bool pJenis_kelamin, char pNo_telp[], char pEmail[]){
	ptrnode tmpNode = (ptrnode) malloc(sizeof(Tnode)); //Alokasi memori
	
	//Masukin data
	tmpNode->_id = _id++;
	strcpy(tmpNode->nama, pNama);
    tmpNode->umur = pUmur;
    tmpNode->jenis_kelamin = pJenis_kelamin;
	strcpy(tmpNode->no_telp, pNo_telp);
	strcpy(tmpNode->email, pEmail);
	tmpNode->next = NULL;
	
	return tmpNode;
}

void printNode(ptrnode tmp){
	printf("%-15s: %d\n", "ID", tmp->_id);
	printf("%-15s: %s\n", "Nama", tmp->nama);
	printf("%-15s: %u\n", "Umur", tmp->umur);
	tmp->jenis_kelamin ? printf("%-15s: Laki-laki\n", "Jenis Kelamin") : printf("%-15s: Perempuan\n", "Jenis Kelamin");
	printf("%-15s: %s\n", "Nomor Telefon", tmp->no_telp);
	printf("%-15s: %s\n", "Alamat Email", tmp->email);
}

void SLL_init(ptrSLL tmpList){
	tmpList->head = NULL; //Inisialisasi head awalnya nunjuk ke NULL
	tmpList->size = 0; //Sizenya juga 0 karena linkedlist masih kosong
}

//curr kepanjangan dari current, artinya yang saat ini
//currList = list saat ini

void SLL_insert(ptrSLL currList, ptrnode currNode, ptrAdjList currAdjList, ptrHashTable currHashTable){ 
	//Kalo SLL kosong, langsung add jadi head, trus size = 1;
    if(currList->head == NULL){
		currList->size++;
		currList->head = currNode;
	}else{
		//Kalo ga kosong ya insert ke tail
		ptrnode tmp = currList->head;

		while(tmp->next != NULL){
			tmp = tmp->next;
		}

		tmp->next = currNode;
		currNode->next = NULL;
		currList->size++;

	}
	
	//Jangan lupa inisialisasi kontak yang baru itu sbg suatu node dalam daftar relasi
	adjList_pushBack(currAdjList, currNode->_id);

	//Ini untuk indexing id nya dengan kontaknya
	hashTable_pushBack(currHashTable, currNode->_id, currNode);
}

void SLL_popFront(ptrSLL currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}else if(currList->size == 1){

		ptrnode tmpNode = currList->head;
		currList->head = NULL;
		currList->size = 0;
		
		free(tmpNode);
	}else{
		
		ptrnode tmpNode = currList->head;
		
		currList->head = currList->head->next;
		tmpNode->next = NULL;
		currList->size--;
		
		free(tmpNode);
	}
}

void SLL_popBack(ptrSLL currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}if(currList->size == 1){
		ptrnode tmpNode = currList->head;
		
		currList->head = NULL;
		currList->size = 0;
		
		free(tmpNode);
	}else{
		ptrnode tmpNode = currList->head;
		ptrnode prev = NULL;

		while(tmpNode->next != NULL){
			prev = tmpNode;
			tmpNode = tmpNode->next;
		}
		
		prev->next = NULL;
		currList->size--;
		
		free(tmpNode);
	}
}

void SLL_deleteNama(ptrSLL currList, char toBeDeleted[]){
	//apabila nilai yang mau dihapus ada di head, maka delete head
	if(strcmp(currList->head->nama, toBeDeleted) == 0){	
		SLL_popFront(currList);
	}else{
		ptrnode cursor = currList->head;
		ptrnode tmp_node = NULL;
		int cnt = 0;

		while(cursor != NULL && strcmp(cursor->nama, toBeDeleted) != 0){
			tmp_node = cursor;
			cursor = cursor->next;
			cnt++;
		}

		//if ini untuk ngecek dia ada di akhir atau bukan
		if(cnt == currList->size){
			//kalo di akhir trus nama yang mau di hapus ada di akhir, maka delete tail
			//tapi klo gaada ya bilang aja gaada karena udh di akhir kan?
			(strcmp(tmp_node->nama, toBeDeleted) != 0) ? printf("Data tidak ditemukan, tidak ada yang dihapus!\n") : SLL_popBack(currList);
		}else{
			//ini kalo misalnya cursor gaada di akhir
			//berarti gabisa popFront atau popBack
			//harus menghapus antara 2 node
		
			tmp_node->next = cursor->next;
			cursor->next = NULL;
			currList->size--;
			free(cursor);
		}
	}
}

ptrnode_1D createNode_1D(int Pnum){
	ptrnode_1D newNode = (ptrnode_1D) malloc(sizeof(Tnode_1D)); //alokasi memori

	//Masukin data
	newNode->data = Pnum;
	newNode->next = NULL;
	return newNode;
}

void SLL_1D_init(ptrSLL_1D tmpList){
	//Sama kaya SLL sebelumnya
	tmpList->head = NULL; 
	tmpList->size = 0;
}

void SLL_1D_pushBack(ptrSLL_1D currList, int data){ //currList -> current List, currNode -> current node
	//Kalo SLL kosong, langsung add jadi head, trus size = 1;
	ptrnode_1D currNode = createNode_1D(data);

    if(currList->head == NULL){
		currList->size++;
		currList->head = currNode;
	}else{
		ptrnode_1D tmp = currList->head;
        
		while(tmp->next != NULL){
			tmp = tmp->next;
		}

		tmp->next = currNode;
		currList->size++;

	}
}

void SLL_1D_popFront(ptrSLL_1D currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}else if(currList->size == 1){
		ptrnode_1D tmpNode = currList->head;
		currList->head = NULL;
		currList->size = 0;
		
		free(tmpNode);
	}else{
		ptrnode_1D tmpNode = currList->head;
		
		currList->head = currList->head->next;
		tmpNode->next = NULL;
		currList->size--;
		
		free(tmpNode);
	}
}

void SLL_1D_popBack(ptrSLL_1D currList){
	if(currList->size == 0){
		printf("List kosong!\n");
	}if(currList->size == 1){
		ptrnode_1D tmpNode = currList->head;
		
		currList->head = NULL;
		currList->size = 0;
		
		free(tmpNode);
	}else{
		ptrnode_1D tmpNode = currList->head;
		ptrnode_1D prev = NULL;

		while(tmpNode->next != NULL){
			prev = tmpNode;
			tmpNode = tmpNode->next;
		}
		
		prev->next = NULL;
		currList->size--;
		
		free(tmpNode);
	}
}

void SLL_1D_deleteNode(ptrSLL_1D currList, int idName){
	//Kurleb sama lah dgn SLL
	ptrnode_1D cursor = currList->head;

	if(cursor->data == idName){	
		SLL_1D_popFront(currList);
	}else{
		ptrnode_1D cursor = currList->head;
		ptrnode_1D tmp_node = NULL;
		int cnt = 0;

		while(cursor != NULL && cursor->data != idName){
			tmp_node = cursor;
			cursor = cursor->next;
			cnt++;
		}

		if(cnt == currList->size){
			(tmp_node->data != idName) ? printf("Data tidak ditemukan, tidak ada yang dihapus!\n") : SLL_1D_popBack(currList);
		}else{
			tmp_node->next = cursor->next;
			cursor->next = NULL;
			currList->size--;
			free(cursor);
		}
	}
}

void adjListNode_init(ptrAdjListNode currAdjListNode){
	currAdjListNode->data_list = NULL; //inisialisasi data_list (row) awalnya kosong
	currAdjListNode->next = NULL;
}

ptrAdjListNode createNode_adj(int src){
	ptrSLL_1D tmp_SLL = (ptrSLL_1D) malloc(sizeof(SLL_1D));
	SLL_1D_init(tmp_SLL);
	SLL_1D_pushBack(tmp_SLL, src);

	ptrAdjListNode tmp_adj = (ptrAdjListNode) malloc(sizeof(adjListNode));
	adjListNode_init(tmp_adj);
	tmp_adj->data_list = tmp_SLL;

	return tmp_adj;
}

void adjList_init(ptrAdjList currAdjList){
	//kurleb sama lah sama SLL
	currAdjList->head = NULL;
	currAdjList->size = 0;
}

void adjList_pushBack(ptrAdjList currAdjList, int src){
	ptrAdjListNode tmpNode = createNode_adj(src); //buat dulu BARIS/ROW nya
	
	//Kalau adjlist-nya kosong, langsung aja tambah baris
	if(currAdjList->head == NULL){
		currAdjList->head = tmpNode;
		currAdjList->size = 1;
	}else{
		//Kalau ga kosong, ya insert tail
		ptrAdjListNode tmp_cursor;
		tmp_cursor = currAdjList->head;

		while(tmp_cursor->next != NULL){
			tmp_cursor = tmp_cursor->next;
		}

		tmp_cursor->next = tmpNode;
		currAdjList->size++;
	}
}

//src adalah source, fin adalah final
void adjList_insertRelation(ptrAdjList currAdjList, int src, int fin){
	ptrAdjListNode cursor = currAdjList->head;

	//Cari letak baris src di adjlist-nya
	while(cursor->data_list->head->data != src){
		cursor = cursor->next;
	}

	//kalau ketemu, insert fin di baris src
	SLL_1D_pushBack(cursor->data_list, fin);
}

void adjList_deleteRelation(ptrAdjList currAdjList, int src, int fin){
	ptrAdjListNode cursor = currAdjList->head;

	//Cari letak baris src di adjlist-nya
	while(cursor->data_list->head->data != src){
		cursor = cursor->next;
	}

	//kalau ketemu, hapus fin dari baris src
	SLL_1D_deleteNode(cursor->data_list, fin);
}

ptritem createItem(int Pkey, ptrnode Pnode){
	ptritem tmp = (ptritem) malloc(sizeof(Titem)); //inisiasi pointer ke item
	ptrnode cpy_node = (ptrnode) malloc(sizeof(Tnode)); //inisiasi pointer ke kontak

	//copy data di kontak ke dalam cpy_node agar indexing tidak terpengaruh saat data dihapus
	cpy_node->_id = Pnode->_id;
	strcpy(cpy_node->nama, Pnode->nama);
    cpy_node->umur = Pnode->umur;
    cpy_node->jenis_kelamin = Pnode->jenis_kelamin;
	strcpy(cpy_node->no_telp, Pnode->no_telp);
	strcpy(cpy_node->email, Pnode->email);
	cpy_node->next = NULL;
	
	tmp->key = Pkey;
	tmp->data = cpy_node;
	tmp->next = NULL;

	return tmp;
}

void hashTable_init(ptrHashTable currHashTable){
	//inisiasi lah ya
	currHashTable->head = NULL;
	currHashTable->capacity = 0;
}

void hashTable_pushBack(ptrHashTable currHashTable, int key, ptrnode currNode){
	ptritem currItem = createItem(key, currNode); //buat dulu itemnya

	//kalo hash table kosong, langsung add ke head, trus capacity ditambah
	if(currHashTable->head == NULL){
		currHashTable->capacity++;
		currHashTable->head = currItem;
	}else{
		//kalo ga ya insert tail
		ptritem tmp = currHashTable->head;

		while(tmp->next != NULL){
			tmp = tmp->next;
		}

		tmp->next = currItem;
		currItem->next = NULL;
		currHashTable->capacity++;
	}
}

ptrnode hashTable_getData(ptrHashTable currHashTable, int Pkey){
	ptritem cursor = currHashTable->head;

	while(cursor != NULL){
		if(cursor->key == Pkey) return cursor->data;
		cursor = cursor->next;
	}

	return NULL;
}

ptrnode merge(ptrnode firstNode, ptrnode secondNode){
    ptrnode merged = (ptrnode)malloc(sizeof(Tnode));
    ptrnode temp = (ptrnode)malloc(sizeof(Tnode));

    merged = temp;

    // while salah satu node menjadi NULL
    while (firstNode != NULL && secondNode != NULL) {
        if (strcmp(firstNode->nama, secondNode->nama) < 0) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }

    // sisa node di firstNode atau secondNode di-insert ke temp
    while (firstNode != NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }

    while (secondNode != NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }

    // return head dari linked list yang terurut setelah dimerge
    return merged->next;
}

// fungsi untuk mengambil node tengah
ptrnode mid_SLL(ptrnode head){
    ptrnode slow = head;
    ptrnode fast = head->next;

    while (slow->next != NULL && (fast != NULL && fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


ptrnode sortNama(ptrnode head){
    if (head->next == NULL) {
        return head;
    }

    ptrnode mid = (ptrnode)malloc(sizeof(Tnode));
    ptrnode head2 = (ptrnode)malloc(sizeof(Tnode));
    mid = mid_SLL(head);
    head2 = mid->next;
    mid->next = NULL; //potong jadi 2 linked list: head, head2 (head dan head2 tidak tersambung)

    //merge 2 linked list yang telah terurut
    ptrnode finalhead = merge(sortNama(head), sortNama(head2));

    return finalhead;
}

ptrnode middle(ptrnode start, ptrnode last){
    // untuk mendapatkan node tengah
    if (start == NULL)
        return NULL;
    ptrnode slow = start;
    ptrnode fast = start->next;
    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

ptrnode cariBinarySearch_nama(ptrSLL daftarKontak, char nama[]){
    ptrnode start = daftarKontak->head;
    ptrnode last = NULL;

    do{
        // temukan node tengah
        ptrnode mid = middle(start, last);
        
		// jika node tengah NULL
        if (mid == NULL)
            return NULL;
        
		// Jika x ditemukan di node tengah
        if (strcmp(mid->nama, nama) == 0)
            return mid;
        
		// Jika nilai x lebih dari node tengah
        else if (strcmp(mid->nama, nama) < 0)
            start = mid->next;
        
		// Jika nilai x kurang dari node tengah
        else
            last = mid;
    } while (last == NULL || last != start);
    
	// jika tidak ditemukan
    return NULL;
}


int cariID(ptrSLL daftarKontak, char nama[]){
	daftarKontak->head = sortNama(daftarKontak->head);
	ptrnode tmp = cariBinarySearch_nama(daftarKontak, nama);
	return tmp == NULL ? -1 : tmp->_id;
}


void editProp(ptrSLL daftarKontak, int flag, int _id, ptrHashTable indeksID){

	char in[20];
	int input=0;

	if(flag < 1 || flag > 5){
		printf("Masukan salah!\n");
		getchar();
	}else{
		ptrnode tmp = daftarKontak->head;
		
		while(tmp->next != NULL && tmp->_id != _id){
			tmp = tmp->next;
		}

		printf("Masukkan data baru: ");
		switch (flag){
			//Nama, No_telp, Email
			case 1:
				getchar();
				gets(in);

				strcpy(tmp->nama, in);
				strcpy(hashTable_getData(indeksID, _id)->nama, in);
				break;
			case 4:
				getchar();
				gets(in);
				
				strcpy(tmp->no_telp, in);
				strcpy(hashTable_getData(indeksID, _id)->no_telp, in);
				break;
			case 5:
				getchar();
				gets(in);

				strcpy(tmp->no_telp, in);
				strcpy(hashTable_getData(indeksID, _id)->email, in);
				break;
			case 2:
				scanf("%d", &input);

				tmp->umur = input;
				hashTable_getData(indeksID, _id)->umur = input;
				break;
			case 3:
				//Jenis Kelamin
				scanf("%d", &input);

				tmp->jenis_kelamin = (bool) input;
				hashTable_getData(indeksID, _id)->jenis_kelamin = (bool) input;
				break;
		}

		printf("Data berhasil diperbarui!\n");
	}
}