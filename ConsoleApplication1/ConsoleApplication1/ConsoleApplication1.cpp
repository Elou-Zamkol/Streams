
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


using namespace std;

auto Zapusk_programmi = []() { cout << "Programma Zapuschena !!!" << endl;  cout << "Voydite v akkaunt dla dalnechoy roboti" << endl; };
auto Zavercheniye_programmi = []() { cout << "Programma Zaverchina !!!" << endl;  cout << "Blogadarim za ispolzovaniye" << endl; };




//======================== C L A S S ===========================================|


class Produkt
{
private:
    char* brend;
    float gram = 0;
    int count = 0;
    float price = 0;
    Produkt* next;

public:

    //--------------------Konstruktori------------------------------------|



    explicit Produkt(const char* brend, float gram, int count, float price) : next(nullptr) {
        int size_1 = strlen(brend);

        this->brend = new char[size_1 + 1];


        for (int i = 0; i < size_1; i++)
        {
            this->brend[i] = brend[i];
        }
        this->brend[size_1] = '\0';

        this->gram = gram;
        this->count = count;
        this->price = price;


    }



    explicit Produkt() {}



    //------------------GET SET---------------------------------|



    Produkt* get_next() {
        return this->next;
    }

    void set_next(Produkt* next) {
        this->next = next;
    }

    const char* get_brend() const {
        return this->brend;
    }


    float get_element() const {
        return this->gram;
    }

    float get_gram() const {
        return this->gram;
    }

    int get_count() const {
        return this->count;
    }

    float get_price() const {
        return this->price;
    }


    void set_brend(const char* brend) {
        if (brend != NULL) {

            int index = strlen(brend);
            char* wrem = new char[index];

            for (int i = 0; i < index; i++)
            {
                wrem[i] = brend[i];

            }
            delete[] this->brend;
            this->brend = new char[index + 1];

            for (int i = 0; i < index; i++)
            {
                this->brend[i] = wrem[i];
            }
            this->brend[index] = '\0';
        }
    }


    void set_count(int count) {
        if (count >= 0) {
            this->count = count;
        }

        else {
            cout << "Kolichestvo ne mochet bit otrichatelnoy" << endl;
        }

    }
    void set_price(float price) {
        if (price >= 1) {
            this->price = price;
        }

        else {
            cout << "Chena ne mochet bit otrichatelnoy" << endl;
        }

    }

    void set_gram(float gram) {
        if (gram >= 1) {
            this->gram = gram;
        }

        else {
            cout << "Ves ne mochet bit otrichatelnoy" << endl;
        }

    }

    //------------------------------------------------------------------------------------|

    void Change() {
        while (true) {
            int variant;
            cout << "1-brend, 2-model, 3-count, 4-price" << endl;
            cout << "Chto vi xotite izmenit: ";
            cin >> variant;

            if (variant == 1) {
                char brend[30];
                cout << "brend: ";
                cin >> brend;
                set_brend(brend);
                break;

            }

            else if (variant == 2) {
                float gram;
                cout << "gram: ";
                cin >> gram;
                set_gram(gram);
                break;

            }

            else if (variant == 3) {
                int count;
                cout << "count: ";
                cin >> count;
                set_count(count);
                break;

            }

            else if (variant == 4) {
                float price;
                cout << "price: ";
                cin >> price;
                set_price(price);
                break;

            }

            else {
                cout << "Takogo elementa net" << endl;
            }
        }
    }


    void Funkchiya_dla_sortirovki(const char* brend, float gram, int count, float price, float pustichka) {
        set_brend(brend);
        set_gram(gram);
        set_count(count);
        set_price(price);
    }


    friend ostream& operator << (ostream& out, const Produkt& other);

};

ostream& operator << (ostream& out, const Produkt& other) {
    return out << " Brend- " << other.brend << "  |  " << "Count- " << other.count << "  |  " << "Vess- " << other.gram << "  |  " << "Price- " << other.price << endl;

}

class Molochnie_produkti : public Produkt {
private:

    float fat_percentage = 0;
    Molochnie_produkti* next;


public:


    explicit Molochnie_produkti(const char* brend, float gram, int count, float price, float fat_percentage) : Produkt(brend, gram, count, price), next(nullptr), fat_percentage(fat_percentage) {}

    explicit Molochnie_produkti() {}

    //--------------------------------------GET SET---------------------|
    float get_element() const {
        return fat_percentage;
    }

    float get_fat_percentage() const {
        return fat_percentage;
    }



    void set_fat_percentage(float fat_percentage) {
        if (fat_percentage >= 0 && fat_percentage <= 100) {
            this->fat_percentage = fat_percentage;
        }

        else {
            cout << " eror" << endl;
        }

    }

    Molochnie_produkti* get_next() {
        return this->next;
    }

    void set_next(Molochnie_produkti* next) {
        this->next = next;
    }

    //-----------------------------------------------------------------------

    void Change() {
        while (true) {
            int variant;
            cout << "1-brend, 2-model, 3-count, 4-price, 5-fat_percentage" << endl;
            cout << "Chto vi xotite izmenit: ";
            cin >> variant;

            if (variant == 1) {
                char brend[30];
                cout << "brend: ";
                cin >> brend;
                set_brend(brend);
                break;

            }

            else if (variant == 2) {
                float gram;
                cout << "gram: ";
                cin >> gram;
                set_gram(gram);
                break;

            }

            else if (variant == 3) {
                int count;
                cout << "count: ";
                cin >> count;
                set_count(count);
                break;

            }

            else if (variant == 4) {
                float price;
                cout << "price: ";
                cin >> price;
                set_price(price);
                break;

            }
            else if (variant == 5) {
                float fat_percentage;
                cout << "fat_percentage: ";
                cin >> fat_percentage;
                set_fat_percentage(fat_percentage);
                break;
            }

            else {
                cout << "Takogo elementa net" << endl;
            }
        }
    }

    void Funkchiya_dla_sortirovki(const char* brend, float gram, int count, float price, float element) {
        set_brend(brend);
        set_gram(gram);
        set_count(count);
        set_price(price);
        set_fat_percentage(element);
    }


    friend ostream& operator << (ostream& out, const Molochnie_produkti& other);

};

ostream& operator << (ostream& out, const Molochnie_produkti& other) {
    return out << " Brend- " << other.get_brend() << "  |  " << "Count- " << other.get_count() << "  |  " << "Vess- " << other.get_gram() << "  |  " << "Price- " << other.get_price() << "  |  " << "Prochent shira- " << other.fat_percentage << endl;

}

class Napitki : public Produkt {
private:
    float Volume = 0;
    Napitki* next;


public:

    explicit Napitki(const char* brend, float gram, int count, float price, float Volume) : Produkt(brend, gram, count, price), next(nullptr), Volume(Volume) { }



    explicit Napitki() {}

    //------------------GET SET---------------------------------|

    float get_element() const {
        return Volume;
    }


    float get_Volume() const {
        return Volume;
    }



    void set_Volume(float Volume) {
        if (Volume > 0) {
            this->Volume = Volume;
        }

        else {
            cout << " eror" << endl;
        }

    }

    Napitki* get_next() {
        return this->next;
    }

    void set_next(Napitki* next) {
        this->next = next;
    }




    //---------------------------------------------------------------


    void Change() {
        while (true) {
            int variant;
            cout << "1-brend, 2-model, 3-count, 4-price, 5-Volume" << endl;
            cout << "Chto vi xotite izmenit: ";
            cin >> variant;

            if (variant == 1) {
                char brend[30];
                cout << "brend: ";
                cin >> brend;
                set_brend(brend);
                break;

            }

            else if (variant == 2) {
                float gram;
                cout << "gram: ";
                cin >> gram;
                set_gram(gram);
                break;

            }

            else if (variant == 3) {
                int count;
                cout << "count: ";
                cin >> count;
                set_count(count);
                break;

            }

            else if (variant == 4) {
                float price;
                cout << "price: ";
                cin >> price;
                set_price(price);
                break;

            }
            else if (variant == 5) {
                float Volume;
                cout << "Volume: ";
                cin >> Volume;
                set_Volume(Volume);
                break;
            }

            else {
                cout << "Takogo elementa net" << endl;
            }
        }
    }

    void Funkchiya_dla_sortirovki(const char* brend, float gram, int count, float price, float element) {
        set_brend(brend);
        set_gram(gram);
        set_count(count);
        set_price(price);
        set_Volume(element);
    }


    friend ostream& operator << (ostream& out, const Napitki& other);

};

ostream& operator << (ostream& out, const Napitki& other) {
    return  out << " Brend- " << other.get_brend() << "  |  " << "Count- " << other.get_count() << " | " << "Vess- " << other.get_gram() << "  |  " << "Price- " << other.get_price() << "  |  " << "Obyem- " << other.Volume << endl;

}





//=========================== L I S T ================================================|



template <typename T>

class List {
private:
    T* head;
    int count = 0;

    bool proverka_sortirofki(const char* model_1, const char* model_2) {
        int count_1 = strlen(model_1);
        int count_2 = strlen(model_2);

        for (int i = 0; i < count_1; i++)
        {

            if (model_2[i] == '\0') {
                break;
            }

            if (model_1[i] != model_2[i]) {

                if (model_1[i] < model_2[i]) {

                    return false;
                }

                else if (model_1[i] > model_2[i]) {

                    return true;
                }
            }
        }

        if (count_1 < count_2) {

            return false;
        }

        else if (count_1 > count_2) {

            return true;
        }
    }


public:
    List() : head(nullptr) {}


    T* get_head() {
        return this->head;
    }

    int return_size() {
        return this->count;
    }

    //------------Proverka---------------|



    bool Proverka_na_kopiyu(const char* brend) {
        bool flag = false;
        if (count != 0) {

            int index = 0;
            T* new_head = head;

            while (index < count)
            {
                if (strcmp(brend, new_head->get_brend()) == 0) {
                    flag = true;
                    return flag;

                }

                new_head = new_head->get_next();
                index++;

            }

            delete[] new_head;
            return flag;

        }
        else {
            return flag;
        }
    }

    int Poisk_elementa_po_brend(const char* brend) {
        if (count != 0) {
            int index = 0;
            T* new_head = head;

            while (index < count)
            {
                if (strcmp(brend, new_head->get_brend()) == 0) {

                    return index;

                }

                new_head = new_head->get_next();
                index++;

            }

            delete[] new_head;
            return -1;

        }


    }

    T Return_element(const char* brend) {
        int index = 0;

        int mesto = Poisk_elementa_po_brend(brend);

        if (count != 0 && mesto != -1) {

            int index = 0;
            T* new_head = this->head;

            while (index <= mesto)
            {

                if (strcmp(brend, new_head->get_brend()) == 0) {

                    return *new_head;


                }
                new_head = new_head->get_next();
                index++;

            }
        }

        else {
            cout << "Takogo persona net livo spisok pustoy :(" << endl;


        }
    }





    //------------------------------------------------|



    void set_head(T* head) {
        this->head = head;
    }

    void Popolnenie_produktov(const char* brend, int count) {
        if (this->count != 0) {

            int index = 0;
            T* safety = head;

            while (index < count)
            {
                if (strcmp(brend, head->get_brend()) == 0) {
                    int new_count = head->get_count() + count;
                    head->set_count(new_count);
                    break;

                }
                head = head->get_next();
                index++;
            }

            head = safety;
        }


    }

    void Ubrat_produktov(const char* brend, int count) {
        if (this->count != 0) {

            int index = 0;
            T* safety = head;

            while (index < count)
            {
                if (strcmp(brend, head->get_brend()) == 0) {
                    int new_count = head->get_count() - count;
                    head->set_count(new_count);
                    break;

                }
                head = head->get_next();
                index++;
            }

            head = safety;
        }


    }


    //-----------------------------Dobavleniye----------------------|



    void push_front(const char* brend, float gram, int count, float price, float element) { // Dobovlenie v nachalo:

        T* new_Person = new T(brend, gram, count, price, element);
        new_Person->set_next(this->head);
        this->head = new_Person;
        this->count++;


    }

    void push_front(const char* brend, float gram, int count, float price) { // Dobovlenie v nachalo:

        T* new_Person = new T(brend, gram, count, price);
        new_Person->set_next(this->head);
        this->head = new_Person;
        this->count++;


    }


    //-------------------------Udalenie----------------------------------|

    void pop_front() {  // udalenie s nacala 1 element:
        if (count != 0) {
            T* new_head = head;
            head = head->get_next();
            delete[] new_head;
            this->count--;

        }

        else {
            cout << "Spisok pustoy" << endl;
        }

    }

    void pop_back() {  // udalenie s koncha 1 element:
        if (count != 0) {
            int index = 0;
            T* safety = head;
            T* new_head = nullptr;
            while (index < count)
            {
                if (index == count - 2) {
                    new_head = head;
                }

                head = head->get_next();
                index++;

            }

            delete[] head;
            new_head->set_next(nullptr);
            head = safety;
            this->count--;


        }

        else {
            cout << "Spisok pustoy" << endl;
        }

    }

    bool dell_Person_for_brend(const char* brend) {  // udalenie elementa po brendu:

        int mesto = Poisk_elementa_po_brend(brend);

        if (count != 0 && mesto != -1) {

            if (mesto > 0 && mesto < count - 1) {

                int index = 0;
                T* safety = head;
                T* element = head;

                while (index <= mesto)
                {
                    if (index == mesto - 1) {
                        element = head->get_next();
                        this->head->set_next(head->get_next()->get_next());


                    }

                    else {
                        head = head->get_next();
                    }

                    index++;

                }

                delete[] element;

                head = safety;
                this->count--;

                return 1;
            }

            else if (mesto == 0) {
                pop_front();


                return 1;

            }

            else if (mesto == count - 1) {
                pop_back();
                return 1;

            }

        }

        else {

            return 0;
        }
    }

    void dell_oll_element() {
        if (this->count != 0) {
            int index = 0;
            T* element = nullptr;

            while (index < count)
            {
                element = head;
                head = head->get_next();
                delete[]element;

                index++;

            }
            cout << endl;
            delete[] head;
            this->count = 0;
        }
    }

    bool dell_count_element_in_karzin(const char* brend, int count) {

        int index = 0;

        int mesto = Poisk_elementa_po_brend(brend);

        if (this->count != 0 && mesto != -1) {

            int index = 0;
            T* safety = this->head;

            while (index <= mesto)
            {

                if (strcmp(brend, head->get_brend()) == 0) {
                    if (this->head->get_count() >= count) {
                        this->head->set_count(this->head->get_count() - count);


                        if (this->head->get_count() == 0) {
                            this->head = safety;

                            if (dell_Person_for_brend(brend)) {
                                return true;
                            }

                        }

                        else {
                            this->head = safety;
                            return true;
                        }

                    }

                    else {
                        this->head = safety;
                        cout << "U vas v korzine net stolko elementov" << endl;
                        return false;
                    }


                }
                this->head = this->head->get_next();
                index++;

            }

            this->head = safety;

        }


        else {
            cout << "Takogo persona net livo spisok pustoy :(" << endl;
            return false;
        }
    }


    //----------------------------------------------------------------------------------|

    bool Change_Produkt(const char* brend) {
        int index = 0;
        bool flag = false;
        if (count != 0) {

            int index = 0;
            T* safety = this->head;

            while (index < this->count)
            {

                if (strcmp(brend, head->get_brend()) == 0) {
                    cout << endl;
                    this->head->Change();
                    flag = true;
                    this->head = safety;
                    return flag;

                }
                this->head = this->head->get_next();
                index++;

            }

            this->head = safety;

            return flag;
        }


        else {
            return flag;
        }
    }


    void Vivod_Element() {  // vivod vseh dannih:
        if (this->count != 0) {
            int index = 0;
            T* new_head = this->head;

            while (index < count)
            {
                cout << *new_head;
                new_head = new_head->get_next();
                index++;

            }
            cout << endl;
            delete[] new_head;
        }

    }


    //--------------------------------Sortirovka--------------------------------------|

    void Sortirovka(int element) {

        if (this->count >= 2) {
            T* safety = this->head;

            bool flag = true;
            int index = 0;

            while (true) {
                int index = 0;
                flag = true;


                while (index < this->count - 1)
                {

                    if (proverka_sortirofki(this->head->get_brend(), this->head->get_next()->get_brend())) {
                        flag = false;

                        if (element == 1) {
                            Produkt* vremen_perem = new Produkt(this->head->get_brend(), this->head->get_gram(), this->head->get_count(), this->head->get_price());

                            this->head->Funkchiya_dla_sortirovki(this->head->get_next()->get_brend(), this->head->get_next()->get_gram(), this->head->get_next()->get_count(), this->head->get_next()->get_price(), 0);

                            this->head->get_next()->Funkchiya_dla_sortirovki(vremen_perem->get_brend(), vremen_perem->get_gram(), vremen_perem->get_count(), vremen_perem->get_price(), 0);

                            delete[] vremen_perem;
                        }

                        else if (element == 2) {
                            Molochnie_produkti* vremen_perem = new Molochnie_produkti(this->head->get_brend(), this->head->get_gram(), this->head->get_count(), this->head->get_price(), this->head->get_element());

                            this->head->Funkchiya_dla_sortirovki(this->head->get_next()->get_brend(), this->head->get_next()->get_gram(), this->head->get_next()->get_count(), this->head->get_next()->get_price(), this->head->get_next()->get_element());

                            this->head->get_next()->Funkchiya_dla_sortirovki(vremen_perem->get_brend(), vremen_perem->get_gram(), vremen_perem->get_count(), vremen_perem->get_price(), vremen_perem->get_element());

                            delete[] vremen_perem;
                        }

                        else if (element == 3) {
                            Napitki* vremen_perem = new Napitki(this->head->get_brend(), this->head->get_gram(), this->head->get_count(), this->head->get_price(), this->head->get_element());

                            this->head->Funkchiya_dla_sortirovki(this->head->get_next()->get_brend(), this->head->get_next()->get_gram(), this->head->get_next()->get_count(), this->head->get_next()->get_price(), this->head->get_next()->get_element());

                            this->head->get_next()->Funkchiya_dla_sortirovki(vremen_perem->get_brend(), vremen_perem->get_gram(), vremen_perem->get_count(), vremen_perem->get_price(), vremen_perem->get_element());

                            delete[] vremen_perem;
                        }

                    }


                    this->head = this->head->get_next();
                    index++;


                }
                this->head = safety;


                if (flag == true) {

                    break;
                }
            }
        }

    }





};



//========================== P O K U P K A    T O V A R A ==========================|




class Pokupatel {
private:
    List<Produkt> karzina1;
    List<Molochnie_produkti> karzina2;
    List<Napitki> karzina3;


    float balans = 0;
    float crat_balans = 0;
    float dolg = 0;


public:
    Pokupatel(float balans, float crat_balans) : balans(balans), crat_balans(crat_balans) {}

    Pokupatel() {}

    void Dobovlenie_v_karzinu(Produkt element, int count) {
        if (karzina1.Proverka_na_kopiyu(element.get_brend()) == false) {
            element.set_count(count);
            karzina1.push_front(element.get_brend(), element.get_gram(), element.get_count(), element.get_price());
            this->dolg += element.get_price() * count;
            karzina1.Sortirovka(1);
        }
        else {
            karzina1.Popolnenie_produktov(element.get_brend(), count);
            this->dolg += element.get_price() * count;
        }
        

    }

    void Dobovlenie_v_karzinu(Molochnie_produkti element, int count) {

        if (karzina2.Proverka_na_kopiyu(element.get_brend()) == false) {
            element.set_count(count);
            karzina2.push_front(element.get_brend(), element.get_gram(), element.get_count(), element.get_price(), element.get_fat_percentage());
            this->dolg += element.get_price() * count;
            karzina2.Sortirovka(2);
        }
        else {
            karzina2.Popolnenie_produktov(element.get_brend(), count);
            this->dolg += element.get_price() * count;
        }

    }

    void Dobovlenie_v_karzinu(Napitki element, int count) {

        if (karzina3.Proverka_na_kopiyu(element.get_brend()) == false) {
            element.set_count(count);
            karzina3.push_front(element.get_brend(), element.get_gram(), element.get_count(), element.get_price(), element.get_Volume());
            this->dolg += element.get_price() * count;
            karzina3.Sortirovka(3);
        }
        else {
            karzina3.Popolnenie_produktov(element.get_brend(), count);
            this->dolg += element.get_price() * count;
        }

    }


    int Udaleniye_iz_korzini(const char* brend, int count) {

        int kuda;
        cout << "Otkuda vi hotite udalit element produkt ? \n1: Otdel Produkti , 2: Otdel Molochnie produkti , 3: Otdel Napitki : ";
        cin >> kuda;
        if (kuda == 1) {
            if (karzina1.dell_count_element_in_karzin(brend, count)) {
                karzina1.Sortirovka(1);
                return 1;

            }

            else {
                return -1;
            }



        }

        else if (kuda == 2) {
            if (karzina2.dell_count_element_in_karzin(brend, count)) {
                karzina2.Sortirovka(2);
                return 2;

            }

            else {
                return -1;
            }

        }

        else if (kuda == 3) {
            if (karzina3.dell_count_element_in_karzin(brend, count)) {
                karzina3.Sortirovka(3);
                return 3;

            }

            else {
                return -1;
            }
        }

        else {
            cout << "Takogo varianta net" << endl;
            return -1;
        }

    }


    void Vivod_korzini() {
        cout << "-----------------Korzina-----------------" << endl;
        cout << endl;
        cout << "--------------------1--------------------" << endl;
        cout << endl;
        karzina1.Vivod_Element();


        cout << "--------------------2--------------------" << endl;
        cout << endl;
        karzina2.Vivod_Element();

        cout << "--------------------3--------------------" << endl;
        cout << endl;
        karzina3.Vivod_Element();
    }


    bool Oplata() {
        while (true) {
            cout << "Balans - " << this->balans << endl;
            cout << "Balans carti - " << this->crat_balans << endl;
            cout << "Dolg - " << this->dolg << endl;

            int variant;
            cout << "Kakoy sposob oplati: 1-Nalichnimi, 2-Kartoy, 3-perevesti dengi na kartu: ";
            cin >> variant;
            if (variant == 1) {
                if (this->dolg <= this->balans) {
                    this->balans -= dolg;
                    this->dolg = 0;
                    karzina1.dell_oll_element();
                    karzina2.dell_oll_element();
                    karzina3.dell_oll_element();
                    return true;
                }

                else {
                    cout << "U vas ne dostatochno sreshtv dla oplati" << endl;
                    return false;
                }
            }

            else if (variant == 2) {
                if (this->dolg <= this->crat_balans) {
                    this->crat_balans -= dolg;
                    this->dolg = 0;
                    karzina1.dell_oll_element();
                    karzina2.dell_oll_element();
                    karzina3.dell_oll_element();
                    return true;
                }

                else {
                    cout << "U vas ne dostatochno sreshtv dla oplati" << endl;
                    return false;
                }
            }

            else if (variant == 3) {
                cout << "Balans - " << this->balans << endl;
                float balans;
                cout << "Vedite summu dla perevoda: ";
                cin >> balans;
                Perenesti_dengi_na_kartu(balans);
            }

            else {
                cout << "takogo varianta net" << endl;
                return false;
            }
        }


    }


    //-----------------------------------------------------------------------------|


    float get_balans() {

        return this->balans;
    }

    float get_crat_balans() {
        return this->crat_balans;
    }

    float get_dolg() {
        return this->dolg;
    }

    void set_dolg(float dolg) {
        if (dolg >= 0) {
            this->dolg = dolg;
        }

        else
        {
            cout << "Dolg ne moget bit otrichatelnim" << endl;
        }

    }


    void Perenesti_dengi_na_kartu(float balans) {
        if (balans > 0) {
            if (this->balans >= balans) {
                this->balans -= balans;
                this->crat_balans += balans;
            }
            else {
                cout << "U vas net stolko deneg" << endl;
            }
        }
        else {
            cout << "Summa ne korekna" << endl;
        }

    }




};



//========================== S K L A D ===========================================|



class Sklad {

private:

    List<Produkt> spisok1;
    List<Molochnie_produkti> spisok2;
    List<Napitki> spisok3;

    Pokupatel* pokupatel;


public:

    Sklad() {}

    Sklad(float balans, float crat_balans) {
        this->pokupatel = new Pokupatel(balans, crat_balans);
    }


    ~Sklad() {
        delete[] pokupatel;
    }

    void Sortirovka_sklada() {
        spisok1.Sortirovka(1);
        spisok2.Sortirovka(2);
        spisok3.Sortirovka(3);
    }

    //======================== F A Y L O V A Y A    S I S T E M A ====================================|


    void Zagruska_danix() {
        int list = 1;
        const char* filename;
        FILE* file = nullptr;
        const char* filename_1 = "Produkt.txt";
        FILE* file_1 = nullptr;
        const char* filename_2 = "Molochnie_produkti.txt";
        FILE* file_2 = nullptr;
        const char* filename_3 = "Napitki.txt";
        FILE* file_3 = nullptr;

        while (list <= 3) {

            filename = filename_1;
            file = file_1;

            if (list == 2) {
                filename = filename_2;
                file = file_2;
            }

            else if (list == 3) {
                filename = filename_3;
                file = file_3;
            }


            if (fopen_s(&file, filename, "r") == 0) {


                char* bfr = new char[100];
                if (file != nullptr) {
                    while (fgets(bfr, 100, file) != nullptr) {
                        int i = 0;
                        char brend[30];
                        float gram = 0;
                        int count = 0;
                        float price = 0;
                        float element = 0;

                        for (; bfr[i] != ' '; i++)
                        {
                            brend[i] = bfr[i];
                        }
                        brend[i] = '\0';
                        i++;



                        int t = 0;
                        char* num1 = new char[8];
                        for (; bfr[i] != ' '; i++, t++)
                        {
                            num1[t] = bfr[i];
                        }
                        num1[t] = '\0';
                        gram = atoi(num1);
                        i++;




                        int k = 0;
                        char* num2 = new char[8];
                        for (; bfr[i] != ' '; i++, k++)
                        {
                            num2[k] = bfr[i];
                        }
                        num2[k] = '\0';
                        count = atoi(num2);
                        i++;



                        if (list == 1) {
                            int c = 0;
                            char* num3 = new char[8];
                            for (; bfr[i] != '\n'; i++, c++)
                            {
                                num3[c] = bfr[i];
                            }
                            num3[c] = '\0';
                            price = atoi(num3);
                            i++;
                            spisok1.push_front(brend, gram, count, price);
                        }


                        if (list == 2 || list == 3) {
                            int c = 0;
                            char* num3 = new char[8];
                            for (; bfr[i] != ' '; i++, c++)
                            {
                                num3[c] = bfr[i];
                            }
                            num3[c] = '\0';
                            price = atoi(num3);
                            i++;

                            int p = 0;
                            char* num4 = new char[8];
                            for (; bfr[i] != '\n'; i++, p++)
                            {
                                num4[p] = bfr[i];
                            }
                            num4[p] = '\0';
                            element = atoi(num4);
                            i++;

                            if (list == 2) {
                                spisok2.push_front(brend, gram, count, price, element);
                            }
                            else if (list == 3) {
                                spisok2.push_front(brend, gram, count, price, element);
                            }


                        }

                    }
                    fclose(file);
                    list++;
                    delete[]bfr;
                }
            }

            else {

                list++;


            }
        }

    }

    void Sohronenie_danix() {

        if (spisok1.return_size() != 0) {
            FILE* file_1 = nullptr;
            const char* filename_1 = "Produkt.txt";
            fopen_s(&file_1, filename_1, "w");

            if (file_1 != nullptr) {

                while (spisok1.get_head() != nullptr)
                {

                    fputs(spisok1.get_head()->get_brend(), file_1);
                    fputs(" ", file_1);
                    char* bfr_1 = new char[10];
                    _itoa_s(spisok1.get_head()->get_gram(), bfr_1, 10, 10);
                    fputs(bfr_1, file_1);
                    fputs(" ", file_1);

                    char* bfr_2 = new char[10];
                    _itoa_s(spisok1.get_head()->get_count(), bfr_2, 10, 10);
                    fputs(bfr_2, file_1);
                    fputs(" ", file_1);
                    char* bfr_3 = new char[10];
                    _itoa_s(spisok1.get_head()->get_price(), bfr_3, 10, 10);
                    fputs(bfr_3, file_1);
                    fputs("\n", file_1);

                    spisok1.set_head(spisok1.get_head()->get_next());
                }

                fclose(file_1);

            }
            cout << "Danie sohraneni - 1" << endl;
        }

        if (spisok2.return_size() != 0) {
            FILE* file_2 = nullptr;
            const char* filename_2 = "Molochnie_produkti.txt";
            fopen_s(&file_2, filename_2, "w");

            if (file_2 != nullptr) {

                while (spisok2.get_head() != nullptr)
                {

                    fputs(spisok2.get_head()->get_brend(), file_2);
                    fputs(" ", file_2);
                    char* bfr_1 = new char[10];
                    _itoa_s(spisok2.get_head()->get_gram(), bfr_1, 10, 10);
                    fputs(bfr_1, file_2);
                    fputs(" ", file_2);

                    char* bfr_2 = new char[10];
                    _itoa_s(spisok2.get_head()->get_count(), bfr_2, 10, 10);
                    fputs(bfr_2, file_2);
                    fputs(" ", file_2);
                    char* bfr_3 = new char[10];

                    _itoa_s(spisok2.get_head()->get_price(), bfr_3, 10, 10);
                    fputs(bfr_3, file_2);
                    fputs(" ", file_2);

                    char* bfr_4 = new char[10];
                    _itoa_s(spisok2.get_head()->get_fat_percentage(), bfr_4, 10, 10);
                    fputs(bfr_4, file_2);
                    fputs("\n", file_2);

                    spisok2.set_head(spisok2.get_head()->get_next());
                }

                fclose(file_2);

            }
            cout << "Danie sohraneni - 2" << endl;
        }

        if (spisok3.return_size() != 0) {
            FILE* file_3 = nullptr;
            const char* filename_3 = "Napitki.txt";
            fopen_s(&file_3, filename_3, "w");

            if (file_3 != nullptr) {

                while (spisok3.get_head() != nullptr)
                {

                    fputs(spisok3.get_head()->get_brend(), file_3);
                    fputs(" ", file_3);

                    char* bfr_1 = new char[10];
                    _itoa_s(spisok3.get_head()->get_gram(), bfr_1, 10, 10);
                    fputs(bfr_1, file_3);
                    fputs(" ", file_3);

                    char* bfr_2 = new char[10];
                    _itoa_s(spisok3.get_head()->get_count(), bfr_2, 10, 10);
                    fputs(bfr_2, file_3);
                    fputs(" ", file_3);

                    char* bfr_3 = new char[10];
                    _itoa_s(spisok3.get_head()->get_price(), bfr_3, 10, 10);
                    fputs(bfr_3, file_3);
                    fputs(" ", file_3);

                    char* bfr_4 = new char[10];
                    _itoa_s(spisok3.get_head()->get_Volume(), bfr_4, 10, 10);
                    fputs(bfr_4, file_3);
                    fputs("\n", file_3);

                    spisok3.set_head(spisok3.get_head()->get_next());
                }

                fclose(file_3);

            }
            cout << "Danie sohraneni - 3" << endl;
        }
    }


    //=========================== R A B O T A   S O   S K L A D O M ==================================|


    void Add_element_in_sklad() {

        char brend[30];
        float gram;
        int count;
        float price;
        float seriyniyNomer;
        int variant;

        int kuda;
        cout << "Kuda vi hotite dobavit produkt ? \n1: Otdel Produkti , 2: Otdel Molochnie produkti , 3: Otdel Napitki : ";
        cin >> kuda;
        if (kuda == 1) {

            cout << "brend: ";
            cin >> brend;
            cout << "gram: ";
            cin >> gram;
            cout << "count: ";
            cin >> count;
            cout << "price: ";
            cin >> price;
            if (gram > 0 && count > 0 && price > 0) {
                if (spisok1.Proverka_na_kopiyu(brend) == false) {
                    spisok1.push_front(brend, gram, count, price);
                    cout << endl;
                    cout << "Element dobavlen" << endl;
                    spisok1.Sortirovka(1);


                }

                else {
                    spisok1.Popolnenie_produktov(brend, count);
                }
            }
            else {
                cout << "Element ne dobavlen" << endl;
            }


        }

        else if (kuda == 2) {

            cout << "brend: ";
            cin >> brend;
            cout << "gram: ";
            cin >> gram;
            cout << "count: ";
            cin >> count;
            cout << "price: ";
            cin >> price;
            cout << "fat_percentage: ";
            cin >> seriyniyNomer;

            if (gram > 0 && count > 0 && price > 0 && seriyniyNomer > 0) {
                if (spisok2.Proverka_na_kopiyu(brend) == false) {
                    spisok2.push_front(brend, gram, count, price, seriyniyNomer);
                    cout << endl;
                    cout << "Element dobavlen" << endl;
                    spisok2.Sortirovka(2);


                }

                else {
                    spisok2.Popolnenie_produktov(brend, count);
                }
            }
            else {
                cout << "Element ne dobavlen" << endl;
            }
        }

        else if (kuda == 3) {
            cout << "brend: ";
            cin >> brend;
            cout << "gram: ";
            cin >> gram;
            cout << "count: ";
            cin >> count;
            cout << "price: ";
            cin >> price;
            cout << "Volume: ";
            cin >> seriyniyNomer;
            if (gram > 0 && count > 0 && price > 0 && seriyniyNomer > 0) {
                if (spisok3.Proverka_na_kopiyu(brend) == false) {
                    spisok3.push_front(brend, gram, count, price, seriyniyNomer);
                    cout << endl;
                    cout << "Element dobavlen" << endl;
                    spisok3.Sortirovka(3);


                }

                else {
                    spisok3.Popolnenie_produktov(brend, count);
                }
            }
            else {
                cout << "Element ne dobavlen" << endl;
            }

        }

    }


    void Dell_element_in_sklad() {
        char brend[30];

        int kuda;
        cout << "Otkuda vi hotite udalit produkt ? " << endl << "\n1: Otdel Produkti , 2: Otdel Molochnie produkti , 3: Otdel Napitki" << endl;
        cout << "4 - Esli vi hotite udalit vezde etot element , 5 - Udalit vse." << endl;
        cout << endl;
        cout << "Vach vibor: ";
        cin >> kuda;
        if (kuda == 1) {
            cout << "Vedite brend dla udaleniya: ";
            cin >> brend;
            if (spisok1.dell_Person_for_brend(brend)) {
                spisok1.Sortirovka(1);
                cout << "Udaleni prochlo uspechno" << endl;
            }
            else {
                cout << "Takogo elementa net livo spisok pustoy :(" << endl;
            }

        }

        else if (kuda == 2) {
            cout << "Vedite brend dla udaleniya: ";
            cin >> brend;
            if (spisok2.dell_Person_for_brend(brend)) {
                spisok2.Sortirovka(2);
                cout << "Udaleni prochlo uspechno" << endl;
            }
            else {
                cout << "Takogo elementa net livo spisok pustoy :(" << endl;
            }

        }


        else if (kuda == 3) {
            cout << "Vedite brend dla udaleniya: ";
            cin >> brend;
            if (spisok3.dell_Person_for_brend(brend)) {
                spisok3.Sortirovka(3);
                cout << "Udaleni prochlo uspechno" << endl;
            }
            else {
                cout << "Takogo elementa net livo spisok pustoy :(" << endl;
            }

        }

        else if (kuda == 4) {
            cout << "Vedite brend dla udaleniya: ";
            cin >> brend;
            spisok1.dell_Person_for_brend(brend);
            spisok2.dell_Person_for_brend(brend);
            spisok3.dell_Person_for_brend(brend);
            Sortirovka_sklada();

            cout << "Udaleni elementa uspechno zavercheno" << endl;

        }

        else if (kuda == 5) {
            spisok1.dell_oll_element();
            spisok2.dell_oll_element();
            spisok3.dell_oll_element();

        }

    }


    void Change_element_in_sklad() {
        char brend[30];

        int kuda;
        cout << "Otkuda vi hotite izmenit produkt ? \n1: Otdel Produkti , 2: Otdel Molochnie produkti , 3: Otdel Napitki : ";
        cin >> kuda;
        if (kuda == 1) {
            cout << "Vedite brend dla izmeneniya: ";
            cin >> brend;

            if (spisok1.Change_Produkt(brend)) {
                spisok1.Sortirovka(1);
                cout << "Izmeneniya prochlo uspechno" << endl;
            }


            else {
                cout << "Takogo elementa net livo spisok pustoy :(" << endl;
            }



        }

        else if (kuda == 2) {
            cout << "Vedite brend dla izmeneniya: ";
            cin >> brend;

            if (spisok2.Change_Produkt(brend)) {
                spisok2.Sortirovka(2);
                cout << "Izmeneniya prochlo uspechno" << endl;
            }


            else {
                cout << "Takogo elementa net livo spisok pustoy :(" << endl;
            }

        }


        else if (kuda == 3) {
            cout << "Vedite brend dla izmeneniya: ";
            cin >> brend;
            if (spisok3.Change_Produkt(brend)) {
                spisok3.Sortirovka(3);
                cout << "Izmeneniya prochlo uspechno" << endl;
            }


            else {
                cout << "Takogo elementa net livo spisok pustoy :(" << endl;
            }

        }

    }


    void Vivod_element_in_sklad() {
        cout << "----------------Moi Tovari---------------" << endl;
        cout << endl;

        cout << "--------------------1--------------------" << endl;
        cout << endl;
        spisok1.Vivod_Element();

        cout << "--------------------2--------------------" << endl;
        cout << endl;
        spisok2.Vivod_Element();

        cout << "--------------------3-------------------" << endl;
        cout << endl;
        spisok3.Vivod_Element();

        cout << endl;

    }



    //==================== P O K U P K A   T O V A R A   S O   S K L A D O M  ===================================|


    void Vzat_tovar() {

        char brend[30];
        int count;

        int kuda;
        cout << "Otkuda vi hotite udalit produkt ? \n1: Otdel Produkti , 2: Otdel Molochnie produkti , 3: Otdel Napitki : " << endl;

        cin >> kuda;
        if (kuda == 1) {
            cout << "Vedite brend dla vzatiya: ";
            cin >> brend;
            cout << "Vedite skolko hotite vzat: ";
            cin >> count;


            if ((spisok1.Return_element(brend).get_count() - count) >= 0) {

                pokupatel->Dobovlenie_v_karzinu(spisok1.Return_element(brend), count);
                spisok1.Ubrat_produktov(brend, count);
                cout << endl;
                cout << "-Tovar vzat-" << endl;
                cout << endl;


            }
            else {
                cout << "Vzat tovr ne udalos" << endl;
            }

        }

        else if (kuda == 2) {
            cout << "Vedite brend dla vzatiya: ";
            cin >> brend;
            cout << "Vedite skolko hotite vzat: ";
            cin >> count;


            if ((spisok2.Return_element(brend).get_count() - count) >= 0) {
                pokupatel->Dobovlenie_v_karzinu(spisok2.Return_element(brend), count);
                spisok2.Ubrat_produktov(brend, count);
                cout << endl;
                cout << "-Tovar vzat-" << endl;
                cout << endl;
            }
            else {
                cout << "Vzat tovr ne udalos" << endl;
            }
        }

        else if (kuda == 3) {
            cout << "Vedite brend dla vzatiya: ";
            cin >> brend;
            cout << "Vedite skolko hotite vzat: ";
            cin >> count;


            if ((spisok3.Return_element(brend).get_count() - count) >= 0) {
                pokupatel->Dobovlenie_v_karzinu(spisok3.Return_element(brend), count);
                spisok3.Ubrat_produktov(brend, count);
                cout << endl;
                cout << "-Tovar vzat-" << endl;
                cout << endl;
            }
            else {
                cout << "Vzat tovr ne udalos" << endl;
            }


        }

    }


    void Vernut_tovar() {
        char brend[30];
        int count;

        pokupatel->Vivod_korzini();

        cout << "Vedite brend dla vozvrata: ";
        cin >> brend;

        cout << "Vedite count dla vozvrata: ";
        cin >> count;
        int variant = pokupatel->Udaleniye_iz_korzini(brend, count);

        if (variant == 1) {
            spisok1.Popolnenie_produktov(brend, count);
            pokupatel->set_dolg(pokupatel->get_dolg() - spisok1.Return_element(brend).get_price() * count);
            cout << endl;
            cout << "Tovar vozrachen" << endl;
        }

        else if (variant == 2) {
            spisok2.Popolnenie_produktov(brend, count);
            pokupatel->set_dolg(pokupatel->get_dolg() - spisok2.Return_element(brend).get_price() * count);
            cout << endl;
            cout << "Tovar vozrachen" << endl;
        }

        else if (variant == 3) {
            spisok3.Popolnenie_produktov(brend, count);
            pokupatel->set_dolg(pokupatel->get_dolg() - spisok3.Return_element(brend).get_price() * count);
            cout << endl;
            cout << "Tovar vozrachen" << endl;
        }

        else {
            cout << "Tovar ne udalos vernut" << endl;
        }



    }


    bool Oplata_tovara() {
        if (pokupatel->Oplata()) {

            cout << "Oplata prochla uspechno" << endl;
            return true;
        }

        else {
            return false;
        }
    }

    void Vivod_korzini() {
        this->pokupatel->Vivod_korzini();
    }

};




//========================== V I Z U A L ============================================|



int main() {

    Sklad* sklad = new Sklad(100, 200);
    bool end = true;
    sklad->Zagruska_danix();
    cout << endl;
    sklad->Sortirovka_sklada();
    Zapusk_programmi();
    cout << endl;

    while (end) {
        char login[30];
        char passverd[30];


        cout << "Vedite login - ";
        cin >> login;
        cout << "Vedite passverd - ";
        cin >> passverd;

        if (strcmp(login, "Sklad123") == 0) {
            if (strcmp(passverd, "12345") == 0) {
                int flag;

                while (true) {
                    cout << endl;
                    cout << "1-Vivod, 2-Add, 3-dell , 4-izmenenie, 5-Zaverchenie raboti: ";

                    cin >> flag;
                    cout << endl;
                    if (flag == 1) {
                        sklad->Vivod_element_in_sklad();
                    }

                    else if (flag == 2) {
                        sklad->Add_element_in_sklad();
                    }

                    else if (flag == 3) {
                        sklad->Dell_element_in_sklad();
                    }

                    else if (flag == 4) {
                        sklad->Change_element_in_sklad();
                    }


                    else if (flag == 5) {
                        int zavercheniye;
                        cout << "1-Zaverchit robotu , 2-Viyti iz akkaunta: ";
                        cin >> zavercheniye;
                        if (zavercheniye == 1) {
                            int variant;
                            cout << "Vi hotite sohranit danie: 1-Da , 2-Net: ";
                            cin >> variant;

                            if (variant == 1) {
                                sklad->Sohronenie_danix();
                                cout << endl;
                                Zavercheniye_programmi();
                                end = false;
                                break;

                            }
                            else if (variant == 2) {
                                cout << endl;
                                Zavercheniye_programmi();
                                end = false;
                                break;

                            }

                            else {
                                cout << "Takogo varianta net" << endl;
                            }

                        }
                        else if (zavercheniye == 2) {
                            int variant;
                            cout << "Vi hotite sohranit danie: 1-Da , 2-Net: ";
                            cin >> variant;

                            if (variant == 1) {
                                sklad->Sohronenie_danix();
                                cout << "Vi vichli iz akkaunta" << endl;
                                cout << endl;
                                break;

                            }
                            else if (variant == 2) {
                                cout << "Vi vichli iz akkaunta" << endl;
                                cout << endl;
                                break;

                            }

                            else {
                                cout << "Takogo varianta net" << endl;
                            }

                        }

                        else {
                            cout << "Takogo varianta net" << endl;
                        }


                    }

                    else {
                        cout << "Takogo varianta net" << endl;
                    }

                }

            }

            else {
                cout << endl;
                cout << "Login ili porol ne verniy" << endl;
                cout << endl;
            }

        }

        else if (strcmp(login, "Pokupatel22") == 0) {
            if (strcmp(passverd, "111") == 0) {
                int flag;

                while (true) {
                    cout << endl;
                    cout << "1-Vzat tovar, 2-Vernut tovar, 3-Oplata tovara, 4-Pokazat korzinu, 5-Pokazat spisok tovarov: ";

                    cin >> flag;
                    cout << endl;

                    if (flag == 1) {
                        sklad->Vzat_tovar();

                    }

                    else if (flag == 2) {
                        sklad->Vernut_tovar();
                    }

                    else if (flag == 3) {
                        if (sklad->Oplata_tovara()) {

                            int zavercheniye;
                            cout << "1-Zaverchit robotu , 2-Viyti iz akkaunta: ";
                            cin >> zavercheniye;
                            if (zavercheniye == 1) {
                                end = false;
                                cout << endl;
                                sklad->Sohronenie_danix();
                                Zavercheniye_programmi();
                                break;

                            }
                            else if (zavercheniye == 2) {
                                cout << "Vi vichli iz akkaunta" << endl;
                                cout << endl;
                                break;

                            }

                            else {
                                cout << "Takogo varianta net" << endl;
                            }


                        }

                        else {
                            cout << endl;
                            cout << "-Oplata ne poluchilos-" << endl;
                            cout << endl;

                        }

                    }

                    else if (flag == 4) {
                        sklad->Vivod_korzini();
                    }

                    else if (flag == 5) {
                        sklad->Vivod_element_in_sklad();

                    }

                    else {
                        cout << endl;
                        cout << "Takogo varianta net" << endl;
                    }

                }

            }

            else {
                cout << endl;
                cout << "Login ili porol ne verniy" << endl;
                cout << endl;
            }

        }

        else {
            cout << endl;
            cout << "Login ili porol ne verniy" << endl;
            cout << endl;
        }

    }


    return 0;

}
