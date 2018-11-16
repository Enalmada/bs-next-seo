/* TODO: figure out how to make this more automatic */
/* title override open ticket: https://github.com/garmeeh/next-seo/issues/15 */

[@bs.module "next-seo"] external nextSeoClass: ReasonReact.reactClass = "default";

/*
 type config = {
   .
   "canonical": Js.undefined(string),
   "title": Js.undefined(string),
 };
 */

[@bs.deriving abstract]
type imageType = {
  url: string,
  width: int,
  height: int,
  alt: string,
};

/*
 [@bs.deriving abstract]
 type opengraphType = {
   [@bs.as "type"] [@bs.optional]
   type_: string,
   [@bs.optional]
   locale: string,
   [@bs.optional]
   url: string,
   [@bs.optional]
   title: string,
   [@bs.optional]
   description: string,
   [@bs.as "defaultImageWidth"] [@bs.optional]
   defaultimagewidth: int,
   [@bs.as "defaultImageHeight"] [@bs.optional]
   defaultimageheight: int,
   [@bs.optional]
   images: array(imageType),
   [@bs.as "siteName"] [@bs.optional]
   sitename: string,
 };

 [@bs.deriving abstract]
 type twitterType = {
   [@bs.optional]
   handle: string,
   [@bs.optional]
   site: string,
   [@bs.as "cardType"] [@bs.optional]
   cardtype: string,
 };

 [@bs.deriving abstract]
 type nextSeoConfig = {
   [@bs.optional]
   title: string,
   [@bs.optional]
   description: string,
   [@bs.optional]
   canonical: string,
   [@bs.as "openGraph"] [@bs.optional]
   opengraph: opengraphType,
   [@bs.optional]
   twitter: twitterType,
 };
 */

[@bs.obj]
external makeProps:
  (
    ~title: string=?,
    ~description: string=?,
    ~canonical: string=?,
    ~ogType: string=?,
    ~ogLocale: string=?,
    ~ogUrl: string=?,
    ~ogTitle: string=?,
    ~ogDescription: string=?,
    ~ogDefaultImageWidth: int=?,
    ~ogDefaultImageHeight: int=?,
    ~ogImages: array(imageType)=?,
    ~ogSiteName: string=?,
    ~twitterHandle: string=?,
    ~twitterSite: string=?,
    ~twitterCardType: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~title=?,
      ~description=?,
      ~canonical=?,
      ~ogType=?,
      ~ogLocale=?,
      ~ogUrl=?,
      ~ogTitle=?,
      ~ogDescription=?,
      ~ogDefaultImageWidth=?,
      ~ogDefaultImageHeight=?,
      ~ogImages=?,
      ~ogSiteName=?,
      ~twitterHandle=?,
      ~twitterSite=?,
      ~twitterCardType=?,
      children,
    ) => {
  let finalFinalConfig = {
    "title": title,
    "description": description,
    "canonical": canonical,
    "openGraph": {
      "type": ogType,
      "locale": ogLocale,
      "url":
        if (Belt.Option.isSome(ogUrl)) {
          ogUrl;
        } else {
          canonical;
        },
      "title":
        if (Belt.Option.isSome(ogTitle)) {
          ogTitle;
        } else {
          title;
        },
      "description":
        if (Belt.Option.isSome(ogDescription)) {
          ogDescription;
        } else {
          description;
        },
      "defaultImageWidth": ogDefaultImageWidth,
      "defaultImageHeight": ogDefaultImageHeight,
      "images": ogImages,
      "site_name": ogSiteName,
    },
    "twitter": {
      "handle": twitterHandle,
      "site": twitterSite,
      "cardType": twitterCardType,
    },
  };

  ReasonReact.wrapJsForReason(~reactClass=nextSeoClass, ~props={"config": finalFinalConfig}, children);
};

/* ORIGINAL
type config = {
  .
  "canonical": Js.undefined(string),
  "title": Js.undefined(string),
};

[@bs.module "next-seo"] external nextSeoClass: ReasonReact.reactClass = "default";

let make = (~config=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=nextSeoClass,
    ~props={"config": config |> Js.Undefined.fromOption},
    children,
  );
*/
