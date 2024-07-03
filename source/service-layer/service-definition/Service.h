#ifndef SERVICE_LAYER_SERVICE_BUILDER_SERVICE_H
#define SERVICE_LAYER_SERVICE_BUILDER_SERVICE_H

namespace servicelayer
{

namespace servicebuilder
{

class Service
{
public:

  virtual void initialize() = 0;
  virtual void run()        = 0;

};

}

}

#endif // SERVICE_LAYER_SERVICE_BUILDER_SERVICE_H
