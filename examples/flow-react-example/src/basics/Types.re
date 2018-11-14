[@genType]
type typeWithVars('x, 'y, 'z) =
  | A('x, 'y)
  | B('z);

[@genType]
type optionInt = option(int);

[@genType]
let consumeOption = (x: option(int)) =>
  Belt.Option.(x->(mapWithDefault(0, n => n)));

[@genType]
let consumeOption2 = (x: optionInt) =>
  Belt.Option.(x->(mapWithDefault(0, n => n)));

[@genType]
let testArray = (a: array(option(int))): array(option(int)) => a;

[@genType]
type funType = int => int;

[@genType]
type myFloat = float;

[@genType]
type arrayOfStrings1 = array(string);

[@genType]
type arrayOfStrings2 = Js.Array.t(string);

[@genType]
type maybeString = Js.null_undefined(string);

[@genType]
type maybeString2 = Js.Null_undefined.t(string);

[@genType]
type peopleArray =
  array({
    .
    "name": string,
    "nickname": Js.nullable(string),
  });

[@genType]
type myObj = Obj.t;

/* Defines a type which maps to `anInterestingFlowType` in `SomeFlowTypes.js` */
[@genType.import "./SomeFlowTypes"]
type anInterestingFlowType;

[@genType]
let identity = (x: anInterestingFlowType) => x;

[@genType.import "./SomeFlowTypes"]
type weekday;

[@bs.module "./SomeFlowTypes"] external saturday: weekday = "SATURDAY";
[@bs.module "./SomeFlowTypes"] external sunday: weekday = "SUNDAY";
[@bs.module "./SomeFlowTypes"] external monday: weekday = "MONDAY";

[@genType]
let isWeekend = day => day === saturday || day === sunday;

[@genType]
let testFunctionOnOptionsAsArgument = (a: option('a), foo) => foo(a);

[@genType]
type someMutableFields = {
  .
  [@bs.set] "mutable0": string,
  "immutable": int,
  [@bs.set] "mutable1": string,
  [@bs.set] "mutable2": string,
};

[@genType.import "./name-with-dashes"] [@bs.module "./Types.gen"]
external foo: int => int = "";

[@genType.opaque]
type exportOpaqueFromEnums = Enums.weekday;

[@genType]
[@genType.as "DateKey"]
type dateKey = string;

[@genType.opaque]
[@genType.as "DateKeyOpaque"]
type dateKeyOpaque = string;