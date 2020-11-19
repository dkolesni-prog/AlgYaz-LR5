#include <iostream>

#include <string>

#include <unordered_map>

#include <map>

#include <algorithm>

#include <vector>

#include <set>

//1. Создать неупорядоченный ассоциативный массив с повторяющимися значениями ключей
//        (unordered_multimap). Тип ключа – int, тип значения – string.
// Вставить 2 новых значения (insert) c ключом 4.
// Удалить 1 значение (erase) с ключом 2.
// Cкопировать элементы в упорядоченный ассоциативный массив (map).
//2. В полученном массиве (map):
// Посчитать число элементов, имеющих ключи в диапазоне от 1 до 4 (count_if).
// Все ключи выделить в вектор (transform).
//3. В полученном векторе (vector):
// Найти элемент, равный 1 (find).
// Заменить нулевые значения на 2 (replace_if).
// Отсортировать элементы по убыванию (sort).
// Скопировать значения в неупорядоченное множество уникальных элементов (set).
//Результат каждого действия выводить на экран. Вывод осуществлять через for_each.

void show_un_map (std::unordered_multimap<int, std::string>& un_map){
    for (auto& it: un_map) {
        std::cout << it.first << " "<<  it.second <<std::endl ;
    }
    std::cout<<"--------------------------"<<std::endl;
}

void show_map (std::map<int, std::string>& map){
    std::for_each(map.begin(),map.end(), [](std::pair<int, std::string> pair){std::cout << pair.first << " "
    << pair.second << std::endl;});
}

void show_my_vector(std::vector<int>& my_vector) {
    std::for_each(my_vector.begin(), my_vector.end(),[](int i){ std::cout << i << std::endl;});
    std::cout << "--------------------------" << std::endl;
}

int main() {
    std::unordered_multimap<int, std::string> my_un_map;
    int size = 3;
    std::string value;
    for (int i = 0; i < size ; ++i) {
        std::cin >> value;
        my_un_map.insert(std::make_pair(i, value));
    }
    for (int i = 0; i < size ; ++i) {
        std::cin >> value;
        my_un_map.insert(std::make_pair(i, value));
    }
    show_un_map(my_un_map);
    my_un_map.insert(std::make_pair(4, "pen"));
    my_un_map.insert(std::make_pair(4, "pencil"));
    show_un_map(my_un_map);
    my_un_map.erase(2);
    //std::find(my_un_map.begin(),my_un_map.end(), 2);
    show_un_map(my_un_map);
    std::map<int, std::string> my_map;
    std::copy(my_un_map.begin(), my_un_map.end(), std::inserter( my_map, my_map.begin()));
    show_map(my_map);
    int counter1_4 = 0;
    counter1_4 = std::count_if(my_map.begin(), my_map.end(),[](auto& item){if (item.first >= 1 && item.first <= 4) return true; // передаем в () тип содержимого my_map
    else return false;});
    std::cout << " There are " << counter1_4 <<  "with the a key [1...4]" << std::endl;
    std::vector <int> my_vec;
    std::transform (my_map.begin(), my_map.end(), std::back_inserter(my_vec), [](std::pair <int, std::string> item){return item.first;});
    show_my_vector(my_vec);
    auto index_iter = std::find(my_vec.begin(),my_vec.end(),1);
    std::cout<< "the index of element equal to 1 is " << *index_iter << std::endl;
    int index = 0;
    std::replace_if(my_vec.begin(), my_vec.end(),[](int& item){if (item == 0) return true;
    else return false;},2 );
    show_my_vector(my_vec);
    //index = std::distance (my_vec.begin(), index_iter);
    //std::cout<< "the index of element equal to 1 is" << index;
    std::sort(my_vec.begin(),my_vec.end(), [](int& i, int& j){ return i > j;});
    show_my_vector(my_vec);
    std::set <int> my_set;
    std::copy(my_vec.begin(), my_vec.end(),std::inserter(my_set,my_set.begin()));
    std::for_each(my_set.begin(), my_set.end(),[](int i){ std::cout << i  << std::endl;});
    return 0;
}