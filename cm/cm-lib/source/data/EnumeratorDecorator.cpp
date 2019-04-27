#include "EnumeratorDecorator.h"

#include <QVariant>

namespace cm {
namespace data {

class EnumeratorDecorator::Implementation {
public:
    Implementation(EnumeratorDecorator *enumeratorDecorator,
                   int value,
                   const std::map<int, QString> &descriptionMapper)
        : enumeratorDecorator(enumeratorDecorator),
          value(value),
          descriptionManager(descriptionMapper){
    }

    EnumeratorDecorator *enumeratorDecorator{nullptr};
    int value;
    std::map<int, QString> descriptionManager;
};

EnumeratorDecorator::EnumeratorDecorator(Entity *parentEntity,
                                         const QString &key,
                                         const QString &label,
                                         int value,
                                         const std::map<int, QString> &descriptionManager)
    : DataDecorator (parentEntity, key, label) {
    implementation.reset(new Implementation(this, value, descriptionManager));
}

EnumeratorDecorator::~EnumeratorDecorator(){}

int EnumeratorDecorator::value() const {
    return implementation->value;
}

QString EnumeratorDecorator::valueDescription() const {
    if(implementation->descriptionManager.find(implementation->value) != implementation->descriptionManager.end()) {
        return implementation->descriptionManager.at(implementation->value);
    } else {
        return {};
    }
}

EnumeratorDecorator& EnumeratorDecorator::setValue(int value) {
    if(value != implementation->value) {
        implementation->value = value;
        emit valueChanged();
    }

    return *this;
}

QJsonValue EnumeratorDecorator::jsonValue() const {
    return QJsonValue::fromVariant(QVariant(implementation->value));
}

void EnumeratorDecorator::update(const QJsonObject &jsonObject) {
    if (jsonObject.contains(key())) {
        auto valueFromJson = jsonObject.value(key()).toInt();
        setValue(valueFromJson);
    }
}



}}
























