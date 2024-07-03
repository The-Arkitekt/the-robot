namespace utils
{

template<typename FIRST, typename SECOND>
Pair<FIRST, SECOND>::Pair():
  first (),
  second()
{
}

template<typename FIRST, typename SECOND>
Pair<FIRST, SECOND>::Pair(const FIRST& first, const SECOND& second):
  first (first),
  second(second)
{
}

template<typename FIRST, typename SECOND>
Pair<FIRST, SECOND>::~Pair()
{
}

}
