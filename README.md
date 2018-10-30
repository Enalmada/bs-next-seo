# bs-next-seo

## Introduction

Bucklescript + ReasonReact binding for [next-seo](https://github.com/garmeeh/next-seo) components. I write bindings when I needed them in my projects. 
If you find a component is missing, it's because I don't need it (yet).

Cautionary note that I am very new to bindings so confirmation and testing is necessary for anything you want to use as I only tested what I use.
** See [bs-ant-design](https://github.com/thangngoc89/bs-ant-design) repo for original credit on this pattern. **

## Installation
```
npm install --save bs-next-seo
```

* Add `bs-next-seo` to `bs-dependencies` in `bsconfig.json`.


## Usage
```
[@bs.deriving abstract]
type nextSeoConfig = {
  canonical: string,
  title: string,
};

let config = nextSeoConfig(~canonical="https://www.example.com", ~title="Index");

<NextSeo config />
```

## Components

I did the components I needed.  While I usually made an attempt to do all the params technically, I only tested the
ones I needed.  Assume you will need to test everything you want to use well.

## Contributions

All contributions are welcomed.  I intend to merge and release anything you push quickly.

## LICENSE

MIT
