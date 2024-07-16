#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "DataBroker.h"
#include "Observer.h"

namespace gtest
{

enum DataSubject
{
  DATA_SUBJECT_1,
  DATA_SUBJECT_2
};

template<typename T>
class MockObserver : public utils::Observer<T>
{
public:

  MOCK_METHOD(void, update, (const T& object));

};

class DataBrokerTest : public testing::Test
{
protected:

  DataBrokerTest():
    dataBroker()
  {
  }

  ~DataBrokerTest() override
  {
  }

  void SetUp() override
  {
  }

  void TearDown() override
  {
  }

public:

  utils::DataBroker<DataSubject, uint8_t> dataBroker;
};


TEST_F(DataBrokerTest, SingleObserver)
{
  MockObserver<uint8_t> observer;

  dataBroker.registerObserver(DATA_SUBJECT_1, observer);

  EXPECT_CALL(observer, update).Times(1);
 
  uint8_t updateVal = 1U;
  dataBroker.update(DATA_SUBJECT_1, updateVal);
}

TEST_F(DataBrokerTest, TwoObserversUpdateFirst)
{
  MockObserver<uint8_t> firstObserver;
  MockObserver<uint8_t> secondObserver;

  dataBroker.registerObserver(DATA_SUBJECT_1, firstObserver);
  dataBroker.registerObserver(DATA_SUBJECT_2, secondObserver);

  EXPECT_CALL(firstObserver, update(1U)).Times(1);
  EXPECT_CALL(secondObserver, update).Times(0);
 
  uint8_t firstUpdateVal = 1U;
  dataBroker.update(DATA_SUBJECT_1, firstUpdateVal);
}

TEST_F(DataBrokerTest, TwoObserversUpdateSecond)
{
  MockObserver<uint8_t> firstObserver;
  MockObserver<uint8_t> secondObserver;

  dataBroker.registerObserver(DATA_SUBJECT_1, firstObserver);
  dataBroker.registerObserver(DATA_SUBJECT_2, secondObserver);

  EXPECT_CALL(secondObserver, update(2U)).Times(1);
  EXPECT_CALL(firstObserver, update).Times(0);

  uint8_t secondUpdateVal = 2U;
  dataBroker.update(DATA_SUBJECT_2, secondUpdateVal);
}


}
