# graphql-basics

graphql 기본 사용법

--------------------------

- [desc](#desc)
  - [1. 기본 query structure:](#1-기본-query-structure)
  - [2. 기본 create mutation structue :](#2-기본-create-mutation-structue-)
  - [3. 기본 update mutation structure :](#3-기본-update-mutation-structure-)
  - [4. 기본 delete mutation structure:](#4-기본-delete-mutation-structure)
  - [prisma graphcool에서 데이터 모델링 유의사항 :](#prisma-graphcool에서-데이터-모델링-유의사항-)
- [dep](#dep)
- [ref](#ref)
- [tags](#tags)

## desc

### 1. 기본 query structure:
```graphql
query {
  links{
    id
  }
}
```


### 2. 기본 create mutation structue :
- request :
```graphql
mutation{

  createLink
  ( data:
      {url:"dsd", description:"description", postedBy:
        {connect:
          {
          id:"cjh3kssn0v24v0b81tmfmn19t"
          }
        }
    }


  )
  {
    url
    description
    postedBy{
      id
    }
  }
}
```
- response:
```json
{
  "data": {
    "createBookmark": {
      "name": "bookmark1",
      "link": {
        "id": "cjh2oh60d8ml10b81srfevmcc"
      },
      "tags": []
    }
  }
}
```

### 3. 기본 update mutation structure :


request :

```graphql
mutation {
  updateBookmark(
    data:{
      name:"bookm2keks"
    }
    where: {
      # name: "bookmark1" #-> unique 필드가 아니므로 사용 불가능
      id:"cjh9ykxxgnwom0b62yf6x9lz7"
    }
  ) {
    id #이 필드는 딱히 필요없음. 응답값에만 영향
    name #이 필드도 딱히 필요없음. 응답값에만 영향
    #그렇지만 이 중괄호 안에 필드가 적어도 하나 있어야함 (같은 구조여야 함.). 중괄호 생략은 불가능.
  }
}
```
- respone:
```json
{
  "data": {
    "updateBookmark": {
      "id": "cjh9ykxxgnwom0b62yf6x9lz7",
      "name": "bookm2ke212ks"
    }
  }
}

```


### 4. 기본 delete mutation structure:
- request :

```graphql
mutation {
  deleteBookmark(
    where: {
      # name: "bookmark1"  #-> 불가능. bookmark의 name field가 unique값이 아니기 때문.
      id:"cjh9y027kntxe0b625w3lbldm"
    }
  ) {
    name
  }
}
```

- response:
```json
{
  "data": {
    "deleteBookmark": {
      "name": "bookmark323232"
    }
  }
}
```


### prisma graphcool에서 데이터 모델링 유의사항 :

1. id는 모든 타입의 필수 필드
2. createdAt, updatedAt is an optional field which of value handled by server.  

<!-- ## inst
- instruction
  1. dsd
  2. trt -->

## dep

## ref
  - [stackoverflow](https://stackoverflow.com/questions/)
  - [데이터 모델링 관련 : graphcool docs](https://www.graph.cool/docs/reference/database/data-modelling-eiroozae8u#createdat-and-updatedat-fields)

## tags
  #graphql, #prisma



--------------------------


 