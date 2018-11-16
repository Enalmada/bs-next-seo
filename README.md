# bs-next-seo

## Introduction

Bucklescript + ReasonReact binding for [next-seo](https://github.com/garmeeh/next-seo) component. 

** See [bs-ant-design](https://github.com/thangngoc89/bs-ant-design) repo for original credit on this pattern. **

## Installation
```
npm install --save bs-next-seo
```

* Add `bs-next-seo` to `bs-dependencies` in `bsconfig.json`.


## Usage
```
<NextSeo title="something" />
```

## Attributes
```js
    title
    description
    canonical
    ogType
    ogLocale
    ogUrl
    ogTitle
    ogDescription
    ogDefaultImageWidth
    ogDefaultImageHeight
    ogImages
    ogSiteName
    twitterHandle
    twitterSite
    twitterCardType
```

## Notes
I couldn't quite figure out how to bind a config prop in a type safe way.  If you want to support a config prop, 
look at the commented out source and feel free to push a fix.  

## Contributions

All contributions are welcomed.  I intend to merge and release anything you push quickly.

## LICENSE

MIT
