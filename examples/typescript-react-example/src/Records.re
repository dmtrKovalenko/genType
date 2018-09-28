open Belt;

[@genType]
type coord = {
  x: int,
  y: int,
  z: option(int),
};

[@genType]
let origin = {x: 0, y: 0, z: Some(0)};

[@genType]
let computeArea = ({x, y, z}) =>
  Option.(x * y * z->(mapWithDefault(1, n => n)));

[@genType]
let coord2d = (x, y) => {x, y, z: None};

[@genType]
type person = {
  name: string,
  age: int,
  address: option(string),
};

[@genType]
type business = {
  name: string,
  owner: option(person),
  address: option(string),
};

let getOpt = (opt, default, foo) => opt->Option.mapWithDefault(default, foo);

[@genType]
let findAddress = (business: business): list(string) =>
  business.address->getOpt([], a => [a]);

[@genType]
let findAllAddresses = (businesses: array(business)): array(string) =>
  businesses
  ->Array.map(business =>
      business.address->getOpt([], a => [a])
      @ business.owner->getOpt([], p => p.address->getOpt([], a => [a]))
    )
  ->List.fromArray
  ->List.flatten
  ->List.toArray;

[@genType]
type payload('a) = {
  num: int,
  payload: 'a,
};

[@genType]
let getPayload = ({payload}) => payload;

[@genType]
type record = {
  v: int,
  w: int,
};

[@genType]
let getPayloadRecord = ({payload}): record => payload;

[@genType]
let recordValue = {v: 1, w: 1};

[@genType]
let payloadValue = {num: 1, payload: recordValue};

[@genType]
let getPayloadRecordPlusOne = ({payload}): record => {
  ...payload,
  v: payload.v + 1,
};