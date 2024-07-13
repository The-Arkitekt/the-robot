#ifndef SERVICE_LAYER_SERVICE_BUILDER_SERVICE_FACTORY_H
#define SERVICE_LAYER_SERVICE_BUILDER_SERVICE_FACTORY_H

#include "Service.h"

namespace servicelayer
{

namespace servicebuilder
{

class ServiceFactory
{
public:

  static Service * createService();

};

}

}

#endif // SERVICE_LAYER_SERVICE_BUILDER_SERVICE_FACTORY_H
