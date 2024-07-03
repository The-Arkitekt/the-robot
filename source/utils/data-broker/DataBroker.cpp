namespace utils
{

template<typename SUBJECT, typename DATA>
DataBroker<SUBJECT, DATA>::DataBroker():
  subjects (),
  observers()   
{
}

template<typename SUBJECT, typename DATA>
DataBroker<SUBJECT, DATA>::~DataBroker()
{
}

template<typename SUBJECT, typename DATA>
void DataBroker<SUBJECT, DATA>::registerObserver(const SUBJECT& subject, Observer<DATA>& observer)
{
  // Search for matching SUBJECT
  const uint64_t numSubjects = subjects.size();
  for (uint64_t i = 0U; i < numSubjects; ++i)
  {
    if (subject == subjects[i])
    {
      observers[i].push(&observer);
      return;
    }
  }

  // Add the SUBJECT if not found
  ++numSubjects;
  subjects.resize(numSubjects);
  observers.resize(numSubjects);

  observers[numSubjects].push(&observer);
}

template<typename SUBJECT, typename DATA>
void DataBroker<SUBJECT, DATA>::update(const SUBJECT& subject, DATA& data)
{
  // Search for SUBJECT
  const uint64_t numSubjects = subjects.size();
  for (uint64_t i = 0U; i < numSubjects; ++i)
  {
    if (subject == subjects[i])
    {
      // Update each observer
      Observer<DATA>* currentObserver = observers[i].head();
      while (nullptr != currentObserver)
      {
        currentObserver->update(data);
        currentNode = currentNode->child;
      }
    }
  }
}

}
