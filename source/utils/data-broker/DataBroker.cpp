namespace utils
{

template<typename S, typename D>
DataBroker<S,D>::DataBroker():
  observers(LinkedList<Observer<D>* >(nullptr))   
{
}

template<typename S, typename D>
DataBroker<S,D>::~DataBroker()
{
  observers.clear();
}

template<typename S, typename D>
void DataBroker<S,D>::registerObserver(const S& subject, Observer<D>& observer)
{
  observers[subject].pushToBack(&observer);
}

template<typename S, typename D>
void DataBroker<S,D>::update(const S& subject, D& data)
{
  const LinkedList<Observer<D> * >& observerList = observers[subject];
  Node<Observer<D> * > observerNode = observerList.head();
  Node<Observer<D> * > * observerNodePtr = &observerNode;

  while (nullptr != observerNodePtr)
  {
    if (nullptr != observerNodePtr->object)
    {
      observerNodePtr->object->update(data);
    }

    observerNodePtr = observerNodePtr->child;
  }
}

}
