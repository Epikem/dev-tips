console.info('TEST START');

type StoreItem = {
  name: string
};

type APIResponse = ErrorResponse | StoreResponse;
type ErrorResponse = {
  statusCode: number,
  message: string
};

type StoreResponse = StoreItem[];

function getResponse(): APIResponse {
  return {
    statusCode: 200,
    message: 'asd'
  };
}

function isStoreItemArray(array: APIResponse): array is StoreResponse {
  if('length' in array){
    return array[0].name === 'string';
  }
  return false;
}

const response = getResponse();
if(isStoreItemArray(response)) {
  const stores = response[0].name;
} else {
  const val = response;
}


