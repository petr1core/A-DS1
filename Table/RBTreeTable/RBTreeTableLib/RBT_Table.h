//template<class Key, class Value>
//class RBTable : public Table<Key, Value> {
//private:
//	enum class Color { RED, BLACK };
//	int height;
//	RBTable* parent;
//	RBTable* left;
//	RBTable* right;
//	RBTable* current;
//public:
//	// Унаследовано через Table
//	RBTable() { this. }
//	Value* Find(Key _key) override;
//	int Insert(Key _key, Value _val) override;
//	int Delete(Key _key) override;
//	void Reset(void) override;
//	bool IsTabEnded(void) const override;
//	int GoNext(void) override;
//	Key GetKey(void) const override;
//	Value* GetValuePtr(void) const override;
//
//};
//template<class Key, class Value>
//Value* RBTable<Key, Value>::Find(Key _key)
//{
//	if (this->GetKey() < _key) { return left->Find(); }
//	if (this->GetKey() > _key) { return right->Find(); }
//	if (this->GetKey() == _key) { return this->GetValuePtr(); }
//}
//template<class Key, class Value>
//int RBTable<Key, Value>::Insert(Key _key, Value _val)
//{
//
//}
//template<class Key, class Value>
//int RBTable<Key, Value>::Delete(Key _key)
//{
//
//}
//template<class Key, class Value>
//void RBTable<Key, Value>::Reset(void)
//{
//	this->parent = nullptr;
//	this->left = nullptr;
//	this->right = nullptr;
//}
//template<class Key, class Value>
//bool RBTable<Key, Value>::IsTabEnded(void) const
//{
//
//}
//template<class Key, class Value>
//int RBTable<Key, Value>::GoNext(void)
//{
//
//}
//template<class Key, class Value>
//Key RBTable<Key, Value>::GetKey(void) const
//{
//	return this->key;
//}
//template<class Key, class Value>
//Value* RBTable<Key, Value>::GetValuePtr(void) const
//{
//	return &this->value;
//}
