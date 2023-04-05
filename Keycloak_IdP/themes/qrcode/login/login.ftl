<#import "template.ftl" as layout>
<#import "components/atoms/button.ftl" as button>
<#import "components/atoms/button-group.ftl" as buttonGroup>
<#import "components/atoms/checkbox.ftl" as checkbox>
<#import "components/atoms/form.ftl" as form>
<#import "components/atoms/input.ftl" as input>
<#import "components/atoms/link.ftl" as link>
<#import "features/labels/username.ftl" as usernameLabel>



<@layout.registrationLayout
  displayInfo=realm.password && realm.registrationAllowed && !registrationDisabled??
  displayMessage=!messagesPerField.existsError("username", "password")
  ;
  section
>
  <#if section="header">
    <#--  ${msg("loginAccountTitle")}  -->
    <div style="display:grid; place-items: center;">
    <img style="width:180;height:180" src="${url.resourcesPath}/dist/images/logo.png">
    </div>
    <div style=" display:grid; place-items: center;font-size: 1em;text-align: center;word-wrap:break-word;">
            <h6>Veuillez scanner ce QR CODE avec l'application DIGITAL ID MAURITANIE <br> sur votre mobile pour vous connecter</h6>
    </div>
    <#elseif realm.password>
      <script
          src="${url.resourcesPath}/dist/js/qrcode.min.js"
      ></script>
        
        <input
          name="url" type="hidden"
          value="<#if realm.password>${url.loginAction}</#if>"
        >
        
        <input
          name="credentialId"
          type="hidden"
          value="<#if auth.selectedCredential?has_content>${auth.selectedCredential}</#if>"
        >

        <div style="display:grid; place-items: center;">
            <div style="display:grid; place-items: center;">
                <div>
                    <div class="qr-code"></div>
                </div>
                <br>
                <div id="qrstring" style="width:55%;font-size: 1em;text-align: center;word-wrap:break-word;">
                </div>
            </div>
        </div>
        <script src="${url.resourcesPath}/dist/js/minified/prod.min.js" type="text/javascript"></script>
  </#if>
</@layout.registrationLayout>


