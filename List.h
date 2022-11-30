#pragma once
#include <iostream>

template <typename T>
struct Cell
{
	T value;//値
	Cell* prev;//前のセルを指すポインタ
	Cell* next;//次のセルを指すポインタ

	//コンストラクタ
	Cell()
	{
		//ダミーノード
		prev = this;
		next = this;
	}

	Cell(T value_, Cell* prev_, Cell* next_)
	{
		//ノード
		value = value_;
		prev = prev_;
		next = next_;
	}
};

template <class T>
class List
{
public:

	List()
	{
		dummy = new Cell<T>();
		size = 0;
	}

	//一番前に追加
	void PushFront(T value_)
	{
		Cell<T>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void PushBack(T value_)
	{
		Cell<T>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next;
		}

		//追加
		Add(value_, tmpCell);
	}

	//任意の場所が存在するかどうか
	bool Search(int num)
	{
		if (num < 0 || num > size)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// 任意の場所の値を変更
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">変更する場所(0~)</param>
	bool ChangeValue(T value_, int num)
	{
		if (Search(num))
		{
			Cell<T>* tmpCell = nullptr;
			tmpCell = dummy;

			//任意の場所まで移動
			for (int i = 0; i < num + 1; i++)
			{
				tmpCell = tmpCell->next;
			}

			//変更
			tmpCell->value = value_;

			return true;
		}

		return false;
	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void Dump()
	{
		Cell<T>* ptr = dummy->next;

		std::cout << "要素一覧:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << ',' << std::endl;
			ptr = ptr->next;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	/// <summary>
	/// 任意の要素の表示
	/// </summary>
	void Specifyvalue(int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
			index++;
		}

		std::cout << index << ':' << tmpCell->value << '\n';
	}

	//任意の要素の取得
	T Getvalue(int num)
	{
		Cell<T>* tmpCell = nullptr;
		tmpCell = dummy;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell->value;
	}

	/// <summary>
	/// リストのサイズを取得
	/// </summary>
	int Size()
	{
		return size;
	}

	//任意の要素の削除
	bool Delete(int num)
	{
		if (Search(num))
		{
			Cell<T>* tmpCell = nullptr;
			tmpCell = dummy;

			//任意の場所まで移動
			for (int i = 0; i < num + 1; i++)
			{
				tmpCell = tmpCell->next;
			}

			tmpCell->prev->next = tmpCell->next;
			tmpCell->next->prev = tmpCell->next;

			delete tmpCell;

			size--;

			return true;
		}

		return false;
	}

	/// <summary>
	/// 降順・昇順で並び替える
	/// </summary>
	/// <param name="flag"> trueで昇順で並び替える</param>
	/// <returns></returns>
	void Sort(bool flag = true)
	{
		Cell<T>* tmpCell = nullptr;

		Cell<T>* tmpCell2 = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{
			tmpCell = GetCell(i);

			for (int j = (size - 1); j > i; j--)
			{
				tmpCell2 = GetCell(j);
				if (flag)
				{
					if (tmpCell2->value < tmpCell2->prev->value)
					{
						T value = tmpCell2->value;
						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
				else
				{
					if (tmpCell2->value > tmpCell2->prev->value)
					{
						T value = tmpCell2->value;
						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
			}
		}
	}

private:

	Cell<T>* dummy;//ダミー
	int size;//サイズ

	//セルが指した後ろに追加
	void Add(T v, Cell<T>* node)
	{
		//新しいセルを生成
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	//任意のセルを取得
	Cell<T>* GetCell(int num)
	{
		Cell<T>* tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell;
	}
};

template <>
struct Cell<char*>
{
	char value[64]{};//値
	Cell* prev;//前のセルを指すポインタ
	Cell* next;//次のセルを指すポインタ

	//コンストラクタ
	Cell()
	{
		//ダミーノード
		prev = this;
		next = this;
	}

	Cell(const char* value_, Cell* prev_, Cell* next_)
	{
		//ノード
		strcpy_s(value, 64, value_);
		prev = prev_;
		next = next_;
	}
};

template<>
class List<char*>
{
public:

	List()
	{
		dummy = new Cell<char*>();
		size = 0;
	}

	//一番前に追加
	void PushFront(const char* value_)
	{
		Cell<char*>* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void PushBack(const char* value_)
	{
		Cell<char*>* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(const char* value_, int num)
	{
		Cell<char*>* tmpCell = nullptr;
		tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num; i++)
		{
			tmpCell = tmpCell->next;
		}

		//追加
		Add(value_, tmpCell);
	}

	//任意の場所が存在するかどうか
	bool Search(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// 任意の場所の値を変更
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">変更する場所(0~)</param>
	bool ChangeValue(const char* value_, int num)
	{
		if (Search(num))
		{
			Cell<char*>* tmpCell = nullptr;
			tmpCell = dummy;

			//任意の場所まで移動
			for (int i = 0; i < num + 1; i++)
			{
				tmpCell = tmpCell->next;
			}

			//変更
			strcpy_s(tmpCell->value, 64, value_);

			return true;
		}

		return false;
	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void Dump()
	{
		Cell<char*>* ptr = dummy->next;

		std::cout << "要素一覧:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << ',' << std::endl;
			ptr = ptr->next;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	/// <summary>
	/// 任意の要素の表示
	/// </summary>
	void Specifyvalue(int num)
	{
		if (Search(num))
		{
			Cell<char*>* tmpCell = nullptr;
			tmpCell = dummy;

			int index = -1;

			for (int i = 0; i < num + 1; i++)
			{
				tmpCell = tmpCell->next;
				index++;
			}

			std::cout << index << ':' << tmpCell->value << '\n';
		}
	}

	//任意の要素の取得
	char* Getvalue(int num)
	{
		if (Search(num))
		{
			Cell<char*>* tmpCell = nullptr;
			tmpCell = dummy;

			for (int i = 0; i < num + 1; i++)
			{
				tmpCell = tmpCell->next;
			}

			return tmpCell->value;
		}
	}

	/// <summary>
	/// リストのサイズを取得
	/// </summary>
	int Size()
	{
		return size;
	}

	//任意の要素の削除
	bool Delete(int num)
	{
		if (Search(num))
		{
			Cell<char*>* tmpCell = nullptr;
			tmpCell = dummy;

			//任意の場所まで移動
			for (int i = 0; i < num + 1; i++)
			{
				tmpCell = tmpCell->next;
			}

			tmpCell->prev->next = tmpCell->next;
			tmpCell->next->prev = tmpCell->next;

			delete tmpCell;

			size--;

			return true;
		}

		return false;
	}

	/// <summary>
	/// 降順・昇順で並び替える
	/// </summary>
	/// <param name="flag"> trueで昇順で並び替える</param>
	/// <returns></returns>
	void Sort(bool flag = true)
	{
		Cell<char*>* tmpCell = nullptr;
		Cell<char*>* tmpCell2 = nullptr;

		for (int i = 0; i < (size - 1); i++)
		{
			tmpCell = GetCell(i);

			for (int j = (size - 1); j > i; j--)
			{
				tmpCell2 = GetCell(j);
				if (flag)
				{
					if (*tmpCell2->value < *tmpCell2->prev->value)
					{
						char value[64];
						strcpy_s(value, 64, tmpCell2->value);

						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
				else
				{
					if (*tmpCell2->value > *tmpCell2->prev->value)
					{
						char value[64];
						strcpy_s(value, 64, tmpCell2->value);

						ChangeValue(tmpCell2->prev->value, j);
						ChangeValue(value, j - 1);
					}
				}
			}
		}
	}

private:

	Cell<char*>* dummy;//ダミー
	int size;//サイズ

	//セルが指した後ろに追加
	void Add(const char* v, Cell<char*>* node)
	{
		//新しいセルを生成
		Cell<char*>* newNode = new Cell<char*>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	//任意のセルを取得
	Cell<char*>* GetCell(int num)
	{
		Cell<char*>* tmpCell = dummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
		}

		return tmpCell;
	}
};