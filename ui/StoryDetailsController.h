//
//  StoryDetailsController.h
//
//  Created by Craig Smith on 9/11/10.
//  Copyright 2010 Craig Smith. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "StoryBrowser.h"

@class StoryDetailsController;

@interface FrotzImageView : UIImageView  <UIAlertViewDelegate>
{
    StoryDetailsController *__weak m_detailsController;
    NSTimer *m_tapTimer;
    CGRect m_savedBounds;
}
-(void)displayMenu;
@property (nonatomic, getter=isMagnified, readonly) BOOL magnified;
-(void)magnifyImage:(BOOL)toggle;
-(void)doPaste;
@property (nonatomic,weak) StoryDetailsController *detailsController;
@end

@interface StoryDetailsController : UIViewController <UIScrollViewDelegate, UITextFieldDelegate, UIActionSheetDelegate> {

    IBOutlet UITextField *m_titleField;
    IBOutlet UITextField *m_authorField;
    IBOutlet UITextField *m_TUIDField;
    IBOutlet FrotzImageView *m_artworkView;
    IBOutlet UIView *m_textFieldsView;
    IBOutlet UIView *m_buttonsView;
    IBOutlet UIView *m_flipper;
    IBOutlet UIWebView *m_descriptionWebView;
    IBOutlet UIButton *m_infoButton;
    IBOutlet UIButton *m_ifdbButton;
    IBOutlet UIButton *m_playButton;
    IBOutlet UILabel *m_artworkLabel;
    IBOutlet UIView *m_portraitCover;
    IBOutlet UILabel *m_portraitCoverLabel;
    IBOutlet UIView *m_contentView;
    IBOutlet UIButton *m_restartButton;

    BOOL m_willResume;

    NSString *m_title, *m_author, *m_tuid, *m_descriptionHTML;
    StoryInfo *m_storyInfo;
    UIImage *m_artwork;

    StoryBrowser *__weak m_browser;
    FrotzInfo *m_frotzInfoController;
    
    CGSize m_artSizeLandscape, m_artSizePortrait;
}

-(IBAction) toggleArtDescript;
-(void)repositionArtwork:(UIInterfaceOrientation)toInterfaceOrientation;
-(void)clear;
-(void)refresh;
-(void)updateSelectionInstructions:(BOOL)hasPopover;
@property (nonatomic, readonly) BOOL keyboardIsActive;
-(void)dimArtwork:(BOOL)dim;
-(IBAction)playButtonPressed;
-(IBAction)IFDBButtonPressed;
-(IBAction)dismissKeyboard;
-(IBAction)showRestartMenu;

@property(nonatomic,weak) StoryBrowser* storyBrowser;
@property(nonatomic,strong) NSString* storyTitle;
@property(nonatomic,strong) NSString* author;
@property(nonatomic,strong) NSString* descriptionHTML;
@property(nonatomic,strong) StoryInfo* storyInfo;
@property(nonatomic,strong,setter=setTUID:) NSString* tuid;
@property(nonatomic,strong) UIImage* artwork;
@property(nonatomic,strong) UIView* contentView;
@property(nonatomic,strong) UIWebView* descriptionWebView;
@property(nonatomic,strong) UIView* flipper;
@property(nonatomic,strong) UIView* infoButton;
@property(nonatomic,assign) BOOL willResume;
@property(nonatomic,strong) UINavigationController* detailsNavigationController;


@end
