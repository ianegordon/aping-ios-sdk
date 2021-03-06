// Copyright (c) 2013 The Sporting Exchange Limited
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 3. All advertising materials mentioning features or use of this software
// must display the following acknowledgement:
// This product includes software developed by The Sporting Exchange Limited.
// 4. Neither the name of The Sporting Exchange Limited nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE SPORTING EXCHANGE LIMITED ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE SPORTING EXCHANGE LIMITED BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma mark Enums

typedef NS_ENUM(NSInteger, BNGMarketBettingType) {
    BNGMarketBettingTypeUnknown,
    BNGMarketBettingTypeOdds,
    BNGMarketBettingTypeLine,
    BNGMarketBettingTypeRange,
    BNGMarketBettingTypeAsianHandicapDoubleLine,
    BNGMarketBettingTypeAsianHandicapSingleLine,
    BNGMarketBettingTypeFixedOdds,
};

typedef NS_ENUM(NSInteger, BNGMarketType) {
    BNGMarketTypeUnknown,
    BNGMarketTypeMatchOdds,
    BNGMarketTypeAsianHandicap,
    BNGMarketTypeBookingOdds,
    BNGMarketTypeBothTeamsToScore,
    BNGMarketTypeCleanSheet,
    BNGMarketTypeCornerMatchBet,
    BNGMarketTypeCornerOdds,
    BNGMarketTypeCorrectScore,
    BNGMarketTypeCorrectScore2,
    BNGMarketTypeDrawNoBet,
    BNGMarketTypeET,
    BNGMarketTypeFirstCorner,
    BNGMarketTypeFirstGoalOdds,
    BNGMarketTypeFirstGoalScorer,
    BNGMarketTypeFirstHalfGoals,
    BNGMarketTypeHalfTime,
    BNGMarketTypeHalfTimeFullTime,
    BNGMarketTypeHalfTimeScore,
    BNGMarketTypeHalfWithMostGoals,
    BNGMarketTypeHatTrickScored,
    BNGMarketTypeMoneyline,
    BNGMarketTypeNextGoal,
    BNGMarketTypeOddOrEven,
    BNGMarketTypeOverUnder5,
    BNGMarketTypeOverUnder15,
    BNGMarketTypeOverUnder25,
    BNGMarketTypeOverUnder35,
    BNGMarketTypeOverUnder45,
    BNGMarketTypeOverUnder55,
    BNGMarketTypeOverUnder65,
    BNGMarketTypeOverUnder75,
    BNGMarketTypeOverUnder85,
    BNGMarketTypeOverUnder,
    BNGMarketTypePenaltyTaken,
    BNGMarketTypeScoreCast,
    BNGMarketTypeSendingOff,
    BNGMarketTypeShownACard,
    BNGMarketTypeTeamTotalGoals,
    BNGMarketTypeToScoreBothHalves,
    BNGMarketTypeToScore,
    BNGMarketTypeToQualify,
    BNGMarketTypeTotalCorners,
    BNGMarketTypeTotalGoals,
    BNGMarketTypeTotalGoalsIndex,
    BNGMarketTypeTournamentWinner,
    BNGMarketTypeWinBothHalves,
    BNGMarketTypeWinFromBehind,
    BNGMarketTypeWinHalf,
    BNGMarketTypeWinToNil,
    BNGMarketTypeWinner,
    BNGMarketTypeUndifferentiated,
};

/**
 * Includes ancillary information about a market.
 */
@interface BNGMarketCatalogueDescription : NSObject

@property (nonatomic) BNGMarketBettingType bettingType;
@property (nonatomic) BOOL bspMarket;
@property (nonatomic, copy) NSString *clarifications;
@property (nonatomic) BOOL discountAllowed;
@property (nonatomic) NSInteger marketBaseRate;
@property (nonatomic, strong) NSDate *marketTime;
@property (nonatomic) BNGMarketType marketType;
@property (nonatomic) BOOL persistenceEnabled;

/**
 * HTML-ified rules for this `BNGMraketCatalogueDescription`
 */
@property (nonatomic, copy) NSString *rules;

/**
 * Indicates whether the `rules` property includes a start date in the description.
 */
@property (nonatomic) BOOL rulesHasDate;

@property (nonatomic, copy) NSString *regulator;
@property (nonatomic, strong) NSDate *settleTime;
@property (nonatomic, strong) NSDate *suspendTime;
@property (nonatomic) BOOL turnInPlayEnabled;
@property (nonatomic, copy) NSString *wallet;

#pragma mark Transformers

/**
 * Given an bettingType NSString, this method returns the corresponding `BNGMarketBettingType`
 * @param bettingType NSString representation of a `BNGMarketBettingType`
 * @return a `BNGMarketBettingType` which corresponds to the bettingType parameter.
 */
+ (BNGMarketBettingType)marketBettingTypeFromString:(NSString *)bettingType;

/**
 * Given an `BNGMarketBettingType` bettingType, this method returns the corresponding NSString
 * @param bettingType a 'BNGMarketBettingType'
 * @return a NSString which corresponds to the bettingType parameter.
 */
+ (NSString *)stringFromMarketBettingType:(BNGMarketBettingType)bettingType;

/**
 * Given an marketType NSString, this method returns the corresponding `BNGMarketType`
 * @param marketType NSString representation of a `BNGMarketType`
 * @return a `BNGMarketType` which corresponds to the marketType parameter.
 */
+ (BNGMarketType)marketTypeFromString:(NSString *)marketType;

/**
 * Given an `BNGMarketType` marketType, this method returns the corresponding NSString
 * @param marketType a 'BNGMarketType'
 * @return a NSString which corresponds to the marketType parameter.
 */
+ (NSString *)stringFromMarketType:(BNGMarketType)marketType;

@end
